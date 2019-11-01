#include<stdio.h>
#include<conio.h>
#include<string.h>

         //Structure for file value:
struct valu_file
{
    char name[50];
    char phone[11];
    char address[50];
    char email_address[50];
}con;

            //Delete file from record:
void file_delete()
{
    system("cls");
    char name[50],nam[50]=".txt";
    int count;
    fflush(stdin);
    printf("\n\t\tENTER THE FILE NAME:");
    scanf("%[^\n]s",name);
    strcat(name,nam);
    count=remove(name);
    if(count==0)
        printf("FILE DELETED SUCCESSFULLY.\n");
    else
        printf("FILE NOT FOUND SORRY.\n");
}

           //Edit contact:
void edit_contact()
{
    system("cls");
    char name[50],na[50]=".txt";
    fflush(stdin);
    printf("\n\tENTER THE FILE NAME:");
    scanf("%[^\n]s",name);
    strcat(name,na);
    FILE *fp;
    fp=fopen(name,"w+");

    fflush(stdin);
    printf("\n\n\t\t\tNAME:");
    scanf("%[^\n]s",con.name);

    fflush(stdin);
    printf("\n\n\t\t\tPHONE:");
    scanf("%[^\n]s",con.phone);

    fflush(stdin);
    printf("\n\n\t\t\tADDRESS:");
    scanf("%[^\n]s",con.address);

    fflush(stdin);
    printf("\n\n\t\t\tEMAIL-ADDRESS:");
    scanf("%[^\n]s",con.email_address);

    fflush(stdin);
    fputs("\n\t========================",fp);
    fputs("\n\t\tCONTACT LIST OF:\n",fp);
    fputs("\t========================",fp);
    fprintf(fp,"\n\n\t1.NAME          : %s\n",con.name);
    fprintf(fp,"\n\n\t2.PHONE         : %s\n",con.phone);
    fprintf(fp,"\n\n\t3.ADDRESS       : %s\n",con.address);
    fprintf(fp,"\n\n\t4.EMAIL-ADDRESS : %s\n",con.email_address);

}

          //Search for any contact:
void search_contact()
{
    system("cls");
    char name[50],nam[5]=".txt";
    char data;
    fflush(stdin);
    printf("\n\n\tENTER THE CONTACT NAME:");
    scanf("%[^\n]s",name);
    strcat(name,nam);
    FILE *fp;
    fp=fopen(name,"r+");
    while(!feof(fp)){
        data=fgetc(fp);
        printf("%c",data);
    }
}
         //Show the list of all contact:
void list_contact()
{
    system("cls");
    char data;
    FILE *fp;
    fp=fopen("contact.txt","r+");
    while(!feof(fp)){
        data=fgetc(fp);
        printf("%c",data);
    }
}
        //Add new contact:
void new_contact()
{
    system("cls");

    char name[50],ext[5]=".txt";
    char name2[50];
    fflush(stdin);
    printf("\n\n\t\tENTER THE FILE NAME:");
    scanf("%[^\n]s",name);
    strcpy(name2,name);

    strcat(name,ext);
    FILE *fp,*fp2;
    fp=fopen("Contact.txt","a+");
    fp2=fopen(name,"w+");

    printf("\n\n\t\tTO EXIT ENTER BLANK SPACE IN THE NAME INPUT:\n");

    fflush(stdin);
    printf("\n\n\t\t\tNAME:");
    scanf("%[^\n]s",con.name);

    fflush(stdin);
    printf("\n\n\t\t\tPHONE:");
    scanf("%[^\n]s",con.phone);

    fflush(stdin);
    printf("\n\n\t\t\tADDRESS:");
    scanf("%[^\n]s",con.address);

    fflush(stdin);
    printf("\n\n\t\t\tEMAIL-ADDRESS:");
    scanf("%[^\n]s",con.email_address);

    fprintf(fp,"\n\n\tCONTACTLIST OF: %s\n\n",name2);
    fprintf(fp,"\n\t\t1.NAME          : %s\n",con.name);
    fprintf(fp,"\n\t\t2.PHONE         : %s\n",con.phone);
    fprintf(fp,"\n\t\t3.ADDRESS       : %s\n",con.address);
    fprintf(fp,"\n\t\t4.EMAIL-ADDRESS : %s\n",con.email_address);

    fflush(stdin);
    fputs("\n\t========================",fp2);
    fputs("\n\t\tCONTACT LIST OF:\n",fp2);
    fputs("\t========================",fp2);
    fprintf(fp2,"\n\n\t1.NAME          : %s\n",con.name);
    fprintf(fp2,"\n\n\t2.PHONE         : %s\n",con.phone);
    fprintf(fp2,"\n\n\t3.ADDRESS       : %s\n",con.address);
    fprintf(fp2,"\n\n\t4.EMAIL-ADDRESS : %s\n",con.email_address);

}

       //Taking option from the menu:
void option()
{

    int c;

    scanf("%d",&c);
    switch(c)
    {
    case 1:
           {
               new_contact();
               break;
           }
    case 2:
          {
              list_contact();
              break;
          }
    case 3:
           {
               search_contact();
               break;
           }
    case 4:
           {
               edit_contact();
               break;
           }
    case 5:
           {
               file_delete();
               break;
           }
    case 6:
           {
               system("cls");
               printf("\n\n\t\tTHANKS FOR VISITING!!\n\n\n");
               exit(0);

           }

    }
}
        //Display the home screen:
void display()
{
 system("cls");
 printf("\n\n\t\t****WELCOME TO CONTACT MANAGEMENT SYSTEM****\n");
 printf("\n\n\t\t\t\tMAIN MENU\n");
 printf("\n\n\t\t   <============================>\n");
 printf("\n\t\t\t1.ADD NEW CONTACT.\n");
 printf("\n\t\t\t2.LIST ALL CONTACT.\n");
 printf("\n\t\t\t3.SEARCH FOR CONTACT.\n");
 printf("\n\t\t\t4.EDIT A CONTACT.\n");
 printf("\n\t\t\t5.DELETE A CONTACT.\n");
 printf("\n\t\t\t6.EXIT.\n");
 printf("\n\t\t   <============================>");
 printf("\n\n\t\tENTER YOUR CHOICE::");

}
int main()
{
    system("cls");
    display();
    option();
    printf("\n\n\tBACT TO MAIN MENU:PRESS [1]  OR EXIT[0]");
               int a;
               scanf("%d",&a);
               if(a==1){
               display();
                option();
               }
               else
                exit(0);
}
