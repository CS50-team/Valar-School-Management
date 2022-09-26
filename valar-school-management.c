#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Simple School Management System by Mohamed Mostafa

// Functions Declaration
void addstudent(void);
void searchstudent(void);
void marksheet(void);
void studentbills(void);
void rerun(void);

// Struct
typedef struct
{
    string name;
    int age;
    string phone;
    string address;
}valar;
// Struct
typedef struct 
{
    string name;
    string marks;
}x1;
// Struct
typedef struct 
{
    string name;
    string b_status;
    int s_num;
}x2;

// Main Function
int main(void)
{
    int user_choice;
    printf("\n\n(1). Add Student\n\n(2). Search Student\n\n(3). Generate Student Total MarkSheet\n\n(4). Pay Student Bills\n\n(5). Exit\n\n");
    do
    {
        user_choice = get_int("\n[*] Select: ");
        if(user_choice == 1)
        {
            addstudent();
        }
        else if(user_choice == 2)
        {
            searchstudent();
        }  
        else if(user_choice == 3)
        {
            marksheet();
        }
        else if(user_choice == 4)
        {
            studentbills();
        }
        else if(user_choice == 5)
        {
            printf("\n\n[*] Valar School Management Has Been Terminated.\n");
            return 0;
        }
    } while (user_choice < 1 || user_choice > 5);
    
}
// Add Student Information Function
void addstudent(void)
{
    string fname;string lname;int age;string phone;string address;
    do{fname = get_string("\n[+] Student First Name: ");}while(strlen(fname) > 11 || strlen(fname) < 3);
    do{lname = get_string("\n[+] Student Last Name: ");}while(strlen(lname) > 11 || strlen(lname) < 5);
    do{age = get_int("\n[+] Student Age: ");}while(age > 18 || age < 15);
    do{phone = get_string("\n[+] Student Phone Number: ");}while(strlen(phone) > 11 || strlen(phone) < 11);
    address = get_string("\n[+] Student Address: ");

    printf("\n==========================================================================\n");
    printf("Student Full Name: %s %s\n",fname,lname);
    printf("==========================================================================\n");
    printf("Student Age: %i\n",age);
    printf("==========================================================================\n");
    printf("Student Phone: %s\n",phone);
    printf("==========================================================================\n");
    printf("Student Address: %s\n",address);
    printf("==========================================================================\n");
    printf("\n[*] Student Data Saved Sucessfully.\n");
    rerun();
}
// Students Marks Sheet Function
void marksheet(void)
{
    string search_query;x1 mdata[4];
    mdata[0].name = "ahmed elsharkawy";mdata[0].marks = "387";mdata[1].name = "mohamed elziady";mdata[1].marks = "379";
    mdata[2].name = "mostafa elmohammady";mdata[2].marks = "371";mdata[3].name = "abdelrahman abdelgawad";mdata[3].marks = "365";

    search_query = get_string("\n\n[+] Student Name: ");
    if(islower(search_query[0]))
    {
        printf("\n========================================================================================================================\n");
        printf("\n[?] Searching, For Student Marks Sheet If Nothing Showed Up Down Here It's Means That Student Data Is Not Found.\n\n");
        for(int x = 0; x < 4; x++)
        {
            if(strcmp(search_query,mdata[x].name) == 0)
            {
                printf("\n[ Student Total Marks Sheet ]\n\n");
                printf("==================================================\n");
                printf("| Student Full Name: %s\t\t |\n",mdata[x].name);
                printf("==================================================\n");
                printf("| Student Total Marks: %s\t\t\t |\n",mdata[x].marks);
                printf("==================================================\n");
            }
        }
    }
    else if(isupper(search_query[0]))
    {
        printf("\n=====================================================================================\n");
        printf("\n[*] Student First Name And Last Name First Character Must Be LowerCase.\n");
    }
    else
    {
        printf("\n=====================================================================================\n");
        printf("\n[*] Invalid Search Query Syntax Please Write Valid Words Not Numbers.\n");
    }
    rerun();
}
// Search For A Student Function
void searchstudent(void)
{
    string search_query;valar sdata[4];
    sdata[0].name = "ahmed elsharkawy";sdata[0].age = 16;sdata[0].phone = "01010102020";sdata[0].address = "37 Kasr El-Nile St., Down Town";
    sdata[1].name = "mohamed elziady";sdata[1].age = 17;sdata[1].phone = "01212122320";sdata[1].address = "10 Nabil El-Waqqad St., HELIOPOLIS";
    sdata[2].name = "mostafa elmohammady";sdata[2].age = 18;sdata[2].phone = "01214725896";sdata[2].address = "16 Mohamed Ezz El Arab St., EL SAYEDA ZEINAB";
    sdata[3].name = "abdelrahman abdelgawad";sdata[3].age = 17;sdata[3].phone = "01065465425";sdata[3].address = "Al-Ahram Bldg. El-Galaa St., Ramses";

    search_query = get_string("\n\n[+] Student Full Name: ");
    if(islower(search_query[0]))
    {
        printf("\n========================================================================================================================\n");
        printf("\n[?] Searching, For Student Data If Nothing Showed Up Down Here It's Means That Student Data Is Not Found.\n\n");
        for(int x = 0; x < 4;x++)
        {
            if(strcmp(search_query,sdata[x].name) == 0)
            {      
                printf("\n[ Student Data ]\n\n");
                printf("\n==========================================================================\n");
                printf("Student Full Name: %s\n",sdata[x].name);
                printf("==========================================================================\n");
                printf("Student Age: %i\n",sdata[x].age);
                printf("==========================================================================\n");
                printf("Student Phone: %s\n",sdata[x].phone);
                printf("==========================================================================\n");
                printf("Student Address: %s\n",sdata[x].address);
                printf("==========================================================================\n");
            }
        }
    }
    else if(isupper(search_query[0]))
    {
        printf("\n=====================================================================================\n");
        printf("\n[*] Student First Name And Last Name First Character Must Be LowerCase.\n");
    }
    else
    {
        printf("\n=====================================================================================\n");
        printf("\n[*] Invalid Search Query Syntax Please Write Valid Words Not Numbers.\n");
    }
    rerun();
}
// Display Student Due Bills
void studentbills(void)
{
    x2 bdata[4];string student_name;int question;long credit_card = 147852369;int ccv = 225;long credit_in;int ccv_in;int choice;
    int credit_balance = 5000;int bill = 1000;

    bdata[0].s_num = 1;bdata[0].name = "ahmed elsharkawy";bdata[0].b_status = "Not Paid";
    bdata[1].s_num = 2;bdata[1].name = "mohamed elziady";bdata[1].b_status = "Not Paid";
    bdata[2].s_num = 3;bdata[2].name = "mostafa elmohammady";bdata[2].b_status = "Not Paid";
    bdata[3].s_num = 4;bdata[3].name = "abdelrahman abdelgawad";bdata[3].b_status = "Not Paid";

    student_name = get_string("\n\n[+] Student Name: ");
    if(islower(student_name[0]))
    {
        printf("\n========================================================================================================================\n");
        printf("\n[?] Searching, For Student Billing Data If Nothing Showed Up Down Here It's Means That Student Data Is Not Found.\n\n");

        for(int x = 0; x < 4; x++)
        {
            if(strcmp(student_name,bdata[x].name) == 0)
            {
                printf("\n[ Student Billing Data ]\n\n");
                printf("=============================================================================================");
                printf("\n| Student No.\t\t Student Name\t\t\t Bills Status\t\t\t    |\n");
                printf("=============================================================================================");
                printf("\n| %i\t\t\t %s\t\t %s\t\t\t    |\n",bdata[x].s_num,bdata[x].name,bdata[x].b_status);
                printf("=============================================================================================");
                printf("\n\n(1). Pay Student Bill.");
            do 
            {
                question = get_int("\n\n[+] Select: ");
                if(question == 1)
                {
                    printf("\n=====================================================================================\n");
                    printf("\n[ Bill Payment Center ]");
                    printf("\n\n\n(1). Pay Bills With Credit Card.\n");
                    do
                    {
                        choice = get_int("\n[+] Select: ");
                        if(choice == 1)
                        {
                            credit_in = get_long("\n[+] Enter Credit Card Number: ");
                            ccv_in = get_int("\n[+] Enter Credit CCV Number: ");
                            if(credit_in == credit_card && ccv_in == ccv && credit_balance >= bill)
                            {
                                credit_balance -= bill;
                                printf("\n=====================================================================================\n");
                                printf("\n[*] Student Bills Payment Done Succesfully.\n\n[*] Your Credit Card Balance After Payment Is: %i$\n\n",credit_balance);
                            }
                            else if(credit_in != credit_card || ccv_in != ccv)
                            {
                                printf("\n=====================================================================================\n");
                                printf("\n[*] Student Bill Payment Failed, Check Your Credit Card Details, And Try Again.\n\n");
                            }
                            else if(credit_balance < bill)
                            {
                                printf("\n=====================================================================================\n");
                                printf("\n[*] Student Bill Payment Failed, Insufficient Credit Card Balance.\n\n");
                            }
                        }
                    }while (choice < 1 || choice > 1);
                                        
                }
                else if(question == 2)
                {
                    main();
                }
                }while( question < 1 || question > 2);
            }
        }
    }
    else if(isupper(student_name[0]))
    {
        printf("\n=====================================================================================\n");
        printf("\n[*] Student First Name And Last Name First Character Must Be LowerCase.\n");
    }
    else
    {
        printf("\n=====================================================================================\n");
        printf("\n[*] Invalid Search Query Syntax Please Write Valid Words Not Numbers.\n");
    }
    rerun();
}
// Re Run Prompt
void rerun(void)
{
    char q1;
    do
    {
        q1 = get_char("\n[?] Do You Wanna Do Another Action? (Y = Continue / N = Exit): ");
        if(q1 == 'Y' || q1 == 'y')
        {
            main();
        }
        else if(q1 == 'N' || q1 == 'n')
        {
            printf("\n\n[*] Valar School Management Has Been Terminated.\n");
        }
    }while(q1 != 'Y' && q1 != 'y' && q1 != 'N' && q1 != 'n');
}