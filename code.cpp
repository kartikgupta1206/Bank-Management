#include<iostream>
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;
int acc = 3094;
class account
{
public:
int acno;
string name;
int ph_no;
string address;
char gender[10];
string dob;
int deposit;
int pin;
int acc_no;
int cc;
void frontt();
void emplog();
void custlog();
void main_menu();
void create_account(){
system("cls");
cout << "\t\t********************************************************************************";
cout << "\n\t\t* Welcome to the National Bank *";
cout << "\n\t\t********************************************************************************";
cout << "\n\n\t\t\t\t ** APPLICATION FORM **";
cout<<"\n\n\t\t\t Account Number : ";
cin >>acno;
cout<<"\t\t\t Account Holder Name : ";
fflush(stdin);
cin>>name;
fflush(stdin);
cout<<"\t\t\t Phone no [+91] : ";
cin>>ph_no;
fflush(stdin);
cout<<"\t\t\t Date of Birth [DD/MM/YYYY] : ";
cin>>dob;
fflush(stdin);
cout<<"\t\t\t Permanent Address : ";
cin>>address;
fflush(stdin);
cout<<"\t\t\t Gender(Male/Female/Others) : ";
cin>>gender;
fflush(stdin);
cout<<"\t\t\t Opening Balance : Rs. ";
cin>>deposit;
fflush(stdin);
cout<<"\n\t\t +--------------------+---------------------+";
cout<<"\n\t\t |Congratulations! Your account is created |";
cout<<"\n\t\t +--------------------+---------------------+";
acc_no=acc;
getch();
acc++;
cout<<"\n\t\t\t Your Debit card Number is : 5524-0975-"<<acc;
acc_no=cc;
cout<<"\n\t\t\t Set 4 digit PIN : ";
cin>>pin;
int len=1;
cp:
if (pin>0){
for (len = 0; pin > 0; len++) {
pin =pin / 10;
}
}
if(len==4){
cout<<"\n PIN is saved\n Press any key to continue...!";
fflush(stdin);
getch();
}
else
{
cout<<"\n\t\t\t Your Pin is not 4 Digit.";
getch();
cout<<"\n\t\t\t Re-Enter 4 Digit Pin : ";
cin>>pin;
goto cp;
}
}
void modify(){
cout<<"\n\t\t UPDATE YOUR DETAILS";
cout<<"\n\t\t\t Account Holder Name : ";
fflush(stdin);
cin>>name;
fflush(stdin);
cout<<"\t\t\t Phone no [+91] : ";
cin>>ph_no;
fflush(stdin);
cout<<"\t\t\t Date of Birth [DD/MM/YYYY] : ";
cin>>dob;
fflush(stdin);
cout<<"\t\t\t Permanent Address : ";
cin>>address;
fflush(stdin);
cout<<"\t\t\t Gender(Male/Female/Others) : ";
cin>>gender;
fflush(stdin);
cout<<"\n\t\t +--------------------+---------------------+";
cout<<"\n\t\t |Congratulations! Your account is updated |";
cout<<"\n\t\t +--------------------+---------------------+";
acc_no=acc;
getch();
acc++;
acc_no=cc;
cout<<"\n\t\t\t Set 4 digit PIN : ";
cin>>pin;
int len=1;
cp:
if (pin>0){
for (len = 0; pin > 0; len++) {
pin =pin / 10;
}
}
if(len==4){
cout<<"\n PIN is saved\n Press any key to continue...!";
fflush(stdin);
getch();
}
else
{
cout<<"\n\t\t\t Your Pin is not 4 Digit.";
getch();
cout<<"\n\t\t\t Re-Enter 4 Digit Pin : ";
cin>>pin;
goto cp;
}
}
void show_account()
{
cout<<"\n\n\t\t\t Account Number : "<<acno;
fflush(stdin);
cout<<"\n\t\t\t Account Holder Name :"<<name;
fflush(stdin);
cout<<"\n\t\t\t Phone no [+91] :"<<ph_no;
fflush(stdin);
cout<<"\n\t\t\t Date of Birth [DD/MM/YYYY] : "<<dob;
fflush(stdin);
cout<<"\n\t\t\t Permanent Address : "<<address;
fflush(stdin);
cout<<"\n\t\t\t Gender(Male/Female/Others) : "<<gender;
fflush(stdin);
cout<<"\n\t\t\t Opening Balance : Rs."<<deposit;
fflush(stdin);
cout<<"\n\t\t\t Your Debit card Number is : 5524-0975-"<<acc;
}
};
class node
{
public:
account data;
node *next;
node(account value)
{
data = value;
next = NULL;
}
};
void condition(node* head , account a){
int key;
cout<<"\n\t\t Enter your Account Number : ";
cin>>key;
while (head != NULL)
{
if(head->data.acno == key){
a.show_account();
}
else
{
cout<<"\n\t\t Account Not Found ...!";
}
head = head->next;
}
}
void deposit(node* head , account a){
int amount;
int key;
cout<<"\n\t\t Enter your Account Number : ";
cin>>key;
while (head != NULL)
{
if(head->data.acno == key){
cout<<"\n\t\t Enter amount you want to Deposit : Rs. ";
cin>>amount;
a.deposit = a.deposit + amount;
cout<<"\n\t\t Your ACCOUNT BALANCE = Rs."<<a.deposit;
}
else
{
cout<<"\n\t\t Account Not Found ...!";
}
head = head->next;
}
}
void withdraw(node* head , account a){
int amount;
int key;
cout<<"\n\t\t Enter Account Number : ";
cin>>key;
while (head != NULL)
{
if(head->data.acno == key){
cout<<"\n\t\t Enter amount you want to Withdraw : Rs. ";
cin>>amount;
a.deposit = a.deposit - amount;
cout<<"\n\t\t Your ACCOUNT BALANCE = Rs."<<a.deposit;
}
else
{
cout<<"\n\t\t Account Not Found ...!";
}
head = head->next;
}
}
void balance_en(node* head , account a){
int key;
cout<<"\n\t\t Enter your Account Number : ";
cin>>key;
while (head != NULL)
{
if(head->data.acno == key){
cout<<"\n\t\t Your ACCOUNT BALANCE = Rs."<<a.deposit;
}
else
{
cout<<"\n\t\t Account Not Found ...!";
}
head = head->next;
}
}
node *insert_tail(node *&head, account value)
{
node *n = new node(value);
if (head == NULL)
{
head = n;
}
else{
node *temp = head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = n;
}
return head;
}
void deletefn(node* &head)
{
if (head== NULL){
// null
}
if (head->next == NULL) {
delete head;
}
// Find the second last node
node* second_last = head;
while (second_last->next->next != NULL)
second_last = second_last->next;
// Delete last node
delete (second_last->next);
// Change next of second last
second_last->next = NULL;
cout<<"Account Deleted";
}
int main()
{
account a;
string c = "y";
node* head = NULL;
cout << "\t\t\n\t\t\tJaypee Institute of Information Technology";
cout << "\t\t\n\t\t\t\t\tNoida-128";
cout << "\t\t\n\n\t\t\t\tDS Project On Banking System.";
cout << "\t\t\n\n\t\t\t ->Developed By: Kartik,Shaleen,Nitin\n\n";
cout << "\t\t\n\n\t\t\t\tPress Any key to continue...!";
getch();
system("cls");
while (c=="y")
{
getch();
time_t now = time(0);
char* date_time = ctime(&now);
cout<<"\t\t\t\t\t\t\t\t\t"<<date_time;
system("cls");
cout << "\t\t********************************************************************************";
cout << "\n\t\t* Welcome to the National Bank *";
cout << "\n\t\t* Account Management Services *";
cout << "\n\t\t********************************************************************************";
cout << "\n\n\t\t\t\t** ACCOUNT REGISTRATION AND SERVICES **";
cout << "\n\t[1] NEW ACCOUNT";
cout << "\n\t[2] DEPOSIT AMOUNT";
cout << "\n\t[3] WITHDRAW AMOUNT";
cout << "\n\t[4] BALANCE ENQUIRY";
cout << "\n\t[5] SEARCH ACCOUNT";
cout << "\n\t[6] CLOSE AN ACCOUNT";
cout << "\n\t[7] MODIFY AN ACCOUNT";
cout << "\n\t[8] EXIT";
cout << "\n\n\tSelect Your Option (1-8) ";
int choice;
cin>>choice;
switch (choice)
{
case 1:
a.create_account();
insert_tail(head,a);
break;
case 2:
system("cls");
deposit(head, a);
break;
case 3:
system("cls");
withdraw(head , a);
break;
case 4:
system("cls");
balance_en(head, a);
break;
case 5:
system("cls");
condition(head, a);
break;
case 7:
system("cls");
a.modify();
break;
case 6:
system("cls");
deletefn(head);
break;
case 8:
cout<<"THANK YOU";
return -1;
break;
default:
cout<<"WRONG INPUT";
break;
}
}
return 0;
}
