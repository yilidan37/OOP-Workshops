#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;


#define MAX_REC_NO 100

void getName(char* name);

struct Contact {
   char name[31];
   long long phoneNumber;
};

bool valid(long long min, long long max, long long val) {
   return min <= val && val <= max;
}

long long getLongLong(long long min, long long max, const char* valueName) {
   long long val;
   bool done = false;
   while (!done) {
      cin >> val;
      if (cin.fail()) {
         cin.clear();
         cout << "Bad Number, try again: ";
      }
      else {
         if (!valid(min, max, val)) {
            cout << "Invalid " << valueName << "!" << endl 
            << "The "<< valueName <<" must be between " << min << " and " << max << ": ";
         }
         else {
            done = true;
         }
      }
      cin.ignore(1000, '\n');
   }
   return val;
}

long long getPhoneNumber() {
   return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
}

void getContact(Contact* C){
   cout << "Name: ";
   getName(C->name);
   cout << "Phone Number: ";
   C->phoneNumber = getPhoneNumber();
}

void printContact(const Contact* C) {
   cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
}


void getStr(char* str, int len) {
   cin.getline(str, len, '\n');
}

void getName(char* name) {
   getStr(name, 30);
}

bool readContact(Contact* C,FILE* fptr) {
   return fscanf(fptr,"%[^,],%lld", C->name, &C->phoneNumber) == 2;
}

void writeContact(FILE* fptr, const Contact* C) {
   fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
}

int readContacts(Contact* contacts, const char* filename) {
   FILE* fptr = fopen(filename, "r");
   Contact C;
   int num;
   for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++) {
      contacts[num] = C;
   }
   return num;
}

void writeContacts(Contact* contacts, int cntno, const char* filename) {
   FILE* fptr = fopen(filename, "w");
   int num;
   for (num = 0; num < cntno; num++) {
      writeContact(fptr, &contacts[num]);
   }
   fclose(fptr);
}
// displays the user interface menu
int menu() {
   cout << endl 
        <<"1- Add Phone Record " << endl;
   cout << "2- Search           " << endl;
   cout << "3- Sort             " << endl;
   cout << "4- List all         " << endl;
   cout << "0- Exit             " << endl;
   cout << "> ";
   return int(getLongLong(0, 4, "option"));
}
int compare(const Contact* A, const Contact* B) {
   return strcmp(A->name, B->name);
}
void sort(Contact c[], int n) {
   Contact temp;
   for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
         if (compare(&c[j] , &c[j + 1]) > 0) {
            temp = c[j];
            c[j] = c[j + 1];
            c[j + 1] = temp;
         }
      }
   }
}

void toLowerCase(char* lowerCase, const char* str) {
   int i;
   for (i = 0;str[i] && i < 30; i++) {
      lowerCase[i] = str[i] | 0x20;
   }
   lowerCase[i] = 0;
}

bool nameInContact(const Contact* C, const char* nameSubStr) {
   char name[31];
   char subName[31];
   toLowerCase(name, C->name);
   toLowerCase(subName, nameSubStr);
   return strstr(name, subName) != nullptr;
}

int search(Contact* found, const Contact* C, const char* name, int noOfRecs) {
   int i;
   int noOfMatches = 0;
   for (i = 0; i < noOfRecs; i++) {
      if (nameInContact(&C[i], name)) {
         found[noOfMatches] = C[i];
         noOfMatches++;
      }
   }
   return noOfMatches;
}

void printContacts(const Contact* C, int num) {
   for (int i = 0; i < num; i++) {
      printContact(&C[i]);
   }
}

bool yes() {
   char ch;
   ch = cin.get();
   cin.ignore(1000, '\n');
   return ch == 'y' || ch == 'Y';
}

void phoneDir(const char* title, const char* filename) {
   int option;
   Contact C[MAX_REC_NO];
   Contact SearchRes[MAX_REC_NO];
   Contact temp;
   bool changed = false;
   int noOfRecs = readContacts(C, filename);
   int noOfSrchs;
   cout << title << ".................." << endl;
   while (option = menu()) {
      switch (option){
      case 0:
         cout << "Goodbye!" << endl;
         break;
      case 1: // add
         getContact(&temp);
         C[noOfRecs] = temp; 
         noOfRecs++;
         changed = true;
         break;
      case 2: // search
         cout << "Name to search for: ";
         getStr(temp.name, 30);
         noOfSrchs = search(SearchRes, C, temp.name, noOfRecs);
         if (noOfSrchs) {
            printContacts(SearchRes, noOfSrchs);
         }
         else {
            cout << temp.name << ", not found!" << endl;
         }
         break;
      case 3:  // Sort
         sort(C, noOfRecs);
         changed = true;
         break;
      case 4:
         printContacts(C, noOfRecs);
         break;
      }
   }
   if (changed) {
      cout << endl << "The phone diecotry has changed!" << "Save changes? (Y/N): ";
      if (yes()) {
         writeContacts(C, noOfRecs, filename);
         cout << "Changes Saved!!" << endl;
      }
      else {
         cout << "Changes aborted!!" << endl;
      }
   }
   cout << "Goodbye!" << endl;
}


int main() {
   phoneDir("SDDS Phone Directory", "phones.txt");
   return 0;
}
