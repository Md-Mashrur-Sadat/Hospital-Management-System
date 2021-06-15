
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct Staffs{
    char name[20];
    int ID;
    char staffType[15];
    int mobile;
    char address[30];
    int salary;
 }d1;

 struct Doctors{
     char name[20];
     int ID;
     char type[15];
     char address[30];
     int mobile;
 }d2;

 struct Patients{
     char name[20];
     int ID;
     char blood[5];
     char birthdate[20];
     char address[30];
     int mobile;
     char test[30];
     int bill;
 }d3;

    FILE *fs,*fd,*fp;

    void AdminLogin();
    void AdminMenu();
    void Exit();
    void AddStaffInfo();
    void DisplayAllStaff();
    void SearchAStaff();
    int checkid(int t);
    int checkid2(int t);
    int checkid3(int t);
    void EditAStaff();
    void AddDoctorInfo();
    void DisplayAllDoctorInfo();
    void SearchADoctor();
    void EditADoctorInfo();
    void AddPatientRecord();
    void DisplayAllPatientsRecords();
    void SearchAPatientRecord();
    void EditAPatientRecord();



 void main(){
     system("cls");
     printf("                        North South Hospital\n\n");
     printf("                        1.Admin Login \n\n");
     printf("                        2.Exit        \n\n");
     printf("                        Enter Your Choice and then press enter: ");
     int choice;
     scanf("%d", &choice);
     fflush(stdin);

     switch(choice){
         case 1:AdminLogin();
         break;
         case 2:Exit();
         break;
         default:main();
         break;
     }
 }


 void AdminLogin(){

     char passadmin[]={"system"};
     char s1[15];
     int check,i=0;
     char ch='\0';
     printf("\n\nEnter password to login:");
     while(ch!=13)
         {
           ch=getch();
           s1[i++]=ch;
           printf("*");
        }
     s1[i-1]='\0';
     check = strcmp(passadmin,s1);
     if(check==0)
     {
      printf("login successful");
      AdminMenu();
     }
    else
     {
     printf("\nEntered password is wrong!\n");
     AdminLogin();
     }
 }
 void AdminMenu(){
     system("cls");
     printf("                           Welcome To The Admin Menu           \n\n");
     printf("                             1.Add Staff Info            \n\n");
     printf("                             2.Display All Staff Info      \n\n");
     printf("                             3.Search a Staff           \n\n");
     printf("                             4.Edit a Staff            \n\n");
     printf("                             5.Add Doctor Info                 \n\n");
     printf("                             6.Display All Doctor Info         \n\n");
     printf("                             7.Search a Doctor            \n\n");
     printf("                             8.Edit a Doctor Info              \n\n");
     printf("                             9.Add Patient Record             \n\n");
     printf("                             10.Display All Patients Records   \n\n");
     printf("                             11.Search a Patient Record        \n\n");
     printf("                             12.Edit a Patient Record          \n\n");
     printf("                             13.Logout                         \n\n");
     printf("                             Enter your choice and then press enter: ");

     int c;
     scanf("%d", &c);
     fflush(stdin);

     switch(c){

         case 1:AddStaffInfo();
         break;
         case 2:DisplayAllStaff();
         break;
         case 3:SearchAStaff();
         break;
         case 4:EditAStaff();
         break;
         case 5:AddDoctorInfo();
         break;
         case 6:DisplayAllDoctorInfo();
         break;
         case 7:SearchADoctor();
         break;
         case 8:EditADoctorInfo();
         break;
         case 9:AddPatientRecord();
         break;
         case 10:DisplayAllPatientsRecords();
         break;
         case 11:SearchAPatientRecord();
         break;
         case 12:EditAPatientRecord();
         break;
         case 13:main();
         break;
         default:AdminLogin();
         break;
     }


 }

 void AddStaffInfo(){

     system("cls");

     fs=fopen("staffs.dat","ab+");
     fseek(fs,0,SEEK_END);

        printf("Enter name:");
        gets(d1.name);
        printf("\nEnter ID:");
        scanf("%d",&d1.ID);
        fflush(stdin);
        printf("\nEnter staff type:");
        gets(d1.staffType);
        printf("\nEnter mobile number:");
        scanf("%d", &d1.mobile);
        fflush(stdin);
        printf("\nEnter address:");
        gets(d1.address);
        printf("\nEnter salary:");
        scanf("%d",&d1.salary);
        fflush(stdin);
        fwrite(&d1,sizeof(d1),1,fs);

     AdminMenu();

 }

void DisplayAllStaff(){
    system("cls");
     fs=fopen("Staffs.dat","rb+");

    while(fread(&d1,sizeof(d1),1,fs)==1){
        printf("Name:%s\nID:%d\nStaff type:%s\nMobile Number:%d\nAddress:%s\nSalary:%d\n\n",d1.name,d1.ID,d1.staffType,d1.mobile,d1.address,d1.salary);
    }

    getch();
    printf("\n\nEnter any key to go back to Admin Menu");
    AdminMenu();
    fclose(fs);

}

void SearchAStaff(){

    system("cls");

      int d;
      printf("Enter Id you want to search:");
      scanf("%d",&d);
      fflush(stdin);

      fs=fopen("Staffs.dat","rb+");

      while(fread(&d1,sizeof(d1),1,fs)==1)
        {
        if(checkid(d)==0)
        { printf("\n\n The User is avaiable");
          printf("\n\nName:%s",d1.name);
          printf("\n\nID:%d",d1.ID);
          printf("\n\nStaff type:%s",d1.staffType);
          printf("\n\nMobile:%d",d1.mobile);
          printf("\n\nAddress:%s",d1.address);
          printf("\n\nSalary:%d",d1.salary);
          break;

        }
        else{
            printf("\n\n No Such ID is Found");
            break;
        }

        }
    printf("\n\nEnter any key to go back to AdminMenu");
    getch();
    AdminMenu();

}

int checkid(int t){
    rewind(fs);
    while(fread(&d1,sizeof(d1),1,fs)!=0){
    if(d1.ID==t){
    return 0;
    }
    }

    return 1;
}

void EditAStaff(){
    system("cls");

      int d;
      printf("Enter User Id you want to edit:");
      scanf("%d",&d);
      fflush(stdin);

      fs=fopen("Staffs.dat","rb+");

      while(fread(&d1,sizeof(d1),1,fs)==1)
        {
        if(checkid(d)==0){
          printf("\nThe User is availble");
                printf("\nThe member ID:%d",d1.ID);
                printf("\nEnter new Name:");
                gets(d1.name);
                printf("\nEnter new ID:");
                scanf("%d",&d1.ID);
                fflush(stdin);
                printf("\nEnter new Staff type:");
                gets(d1.staffType);
                printf("\nEnter new mobile number:");
                scanf("%d",&d1.mobile);
                fflush(stdin);
                printf("\nEnter new address:");
                gets(d1.address);
                printf("\nEnter new salary:");
                scanf("%d",&d1.salary);
                fflush(stdin);
                printf("\nThe record is modified\n");
                fseek(fs,ftell(fs)-sizeof(d1),0);
                fwrite(&d1,sizeof(d1),1,fs);
                fclose(fs);
          break;

        }
        else{
            printf("\n\n No Such User Is Found");
            break;
        }

        }
    getch();
    printf("\n\nEnter any key to go back to AdminMenu");
    AdminMenu();

}

void AddDoctorInfo(){

    system("cls");
    fd=fopen("Doctors.dat","ab+");
    fseek(fd,0,SEEK_END);

	printf("Enter Name of Doctor :- \n");
	gets(d2.name);
	printf("Enter Id number   :-\n ");
	scanf("%d",&d2.ID);
	fflush(stdin);
	printf("type :- \n");
	gets(d2.type);
	printf("Enter address of doctor :- \n");
	gets(d2.address);
	printf("Enter mobile number- \n");
	scanf("%d",&d2.mobile);
	fflush(stdin);

    fwrite(&d2,sizeof(d2),1,fd);
	fclose(fd);
    AdminMenu();

}


void DisplayAllDoctorInfo(){
    system("cls");
     fd=fopen("Doctors.dat","rb+");

    while(fread(&d2,sizeof(d2),1,fd)==1){
        printf("Name:%s\nID:%d\ntype:%s\nAddress:%s\nMobile Number:%d\n\n",d2.name,d2.ID,d2.type,d2.address,d2.mobile);
    }

    printf("\n\nEnter any key to go back to AdminMenu");
    getch();
    AdminMenu();

	fclose(fd);
}

void SearchADoctor(){

        system("cls");

      int d;
      printf("Enter Id you want to search:");
      scanf("%d",&d);
      fflush(stdin);

      fd=fopen("Doctors.dat","rb+");

      while(fread(&d2,sizeof(d2),1,fd)==1)
        {
        if(checkid2(d)==0)
        { printf("\n\n The User is avaiable");
          printf("\n\nName:%s",d2.name);
          printf("\n\nID:%d",d2.ID);
          printf("\n\nType:%s",d2.type);
          printf("\n\nAddress:%s",d2.address);
          printf("\n\nMobile:%d",d2.mobile);
          break;

        }
        else{
            printf("\n\n No Such ID is Found");
            break;
        }

        }
    printf("\n\nEnter any key to go back to AdminMenu");
    getch();
    AdminMenu();
}
void EditADoctorInfo(){
    system("cls");

      int d;
      printf("Enter Doctor Id you want to edit:");
      scanf("%d",&d);
      fflush(stdin);

      fd=fopen("Doctors.dat","rb+");

      while(fread(&d2,sizeof(d2),1,fd)==1)
        {
        if(checkid2(d)==0){
          printf("\nThe User is availble");
                printf("\nThe doctor ID:%d",d2.ID);
                printf("\nEnter new Name:");
                gets(d2.name);
                printf("\nEnter new ID:");
                scanf("%d",&d2.ID);
                fflush(stdin);
                printf("\nEnter new type:");
                gets(d2.type);
                printf("\nEnter new mobile number:");
                scanf("%d",&d2.mobile);
                fflush(stdin);
                printf("\nEnter new address:");
                gets(d2.address);
                printf("\nThe record is modified\n");
                fseek(fd,ftell(fd)-sizeof(d2),0);
                fwrite(&d2,sizeof(d2),1,fd);
                fclose(fd);
          break;

        }
        else{
            printf("\n\n No Such User Is Found");
            break;
        }


        }
    printf("\n\nEnter any key to go back to AdminMenu");
    getch();
    AdminMenu();

}
int checkid2(int t){
    rewind(fd);
    while(fread(&d2,sizeof(d2),1,fd)!=0){
    if(d2.ID==t){
    return 0;
    }
    }

    return 1;
}

void AddPatientRecord(){
	    system("cls");

     fp=fopen("Patients.dat","ab+");
     fseek(fp,0,SEEK_END);

        printf("Enter name:");
        gets(d3.name);
        printf("\nEnter ID:");
        scanf("%d",&d3.ID);
        fflush(stdin);
        printf("\nEnter blood group:");
        gets(d3.blood);
        printf("\nEnter mobile number:");
        scanf("%d", &d3.mobile);
        fflush(stdin);
        printf("\nEnter Birthdate:");
        gets(d3.birthdate);
        printf("\nEnter address:");
        gets(d3.address);
        printf("\nEnter test:");
        gets(d3.test);
        printf("\nEnter bill:");
        scanf("%d",&d3.bill);
        fflush(stdin);

        fwrite(&d3,sizeof(d3),1,fp);

     AdminMenu();

}
void DisplayAllPatientsRecords(){
	 system("cls");
     fp=fopen("Patients.dat","rb+");

    while(fread(&d3,sizeof(d3),1,fp)==1){
        printf("Name:%s\nID:%d\nBlood group:%s\nBirthdate:%s\nMobile Number:%d\nAddress:%s\nTest:%s\nBill:%d\n\n",d3.name,d3.ID,d3.blood,d3.birthdate,d3.mobile,d3.address,d3.test,d3.bill);
    }
    printf("\n\nEnter any key to go back to AdminMenu");
    getch();
    AdminMenu();

    printf("function is working");
}

void SearchAPatientRecord(){
    system("cls");

      int d;
      printf("Enter Id you want to search:");
      scanf("%d",&d);
      fflush(stdin);

      fp=fopen("Patients.dat","rb+");

      while(fread(&d3,sizeof(d3),1,fp)==1)
        {
        if(checkid3(d)==0)
        { printf("\nThe User is avaiable");
          printf("\n\nName:%s",d3.name);
          printf("\n\nID:%d",d3.ID);
          printf("\n\nBlood group:%s",d3.blood);
          printf("\n\nMobile:%d",d3.mobile);
          printf("\n\nAddress:%s",d3.address);
          printf("\n\nBill:%d",d3.bill);
          printf("\n\nTest:%s",d3.test);
          printf("\n\nBirthdate:%s",d3.birthdate);
          break;

        }
        else{
            printf("\n\n No Such ID is Found");
            break;
        }

    }
    printf("\n\nEnter any key to go back to AdminMenu");
    getch();
    AdminMenu();
}

void EditAPatientRecord(){
    system("cls");
    int d;
    printf("Enter Patient Id you want to edit:");
    scanf("%d",&d);
    fflush(stdin);

    fp=fopen("Patients.dat","rb+");

    while(fread(&d3,sizeof(d3),1,fp)==1)
        {
        if(checkid3(d)==0){
          printf("\nThe User is availble");
                printf("\nThe patient ID:%d",d3.ID);
                printf("\nEnter new Name:");
                gets(d3.name);
                printf("\nEnter new ID:");
                scanf("%d",&d3.ID);
                fflush(stdin);
                printf("\nEnter new blood group:");
                gets(d3.blood);
                printf("\nEnter new mobile number:");
                scanf("%d",&d3.mobile);
                fflush(stdin);
                printf("\nEnter new address:");
                gets(d3.address);
                printf("\nEnter new birthdate:");
                gets(d3.birthdate);
                printf("\nEnter new test:");
                gets(d3.test);
                printf("\nThe record is modified\n");
                fseek(fp,ftell(fp)-sizeof(d3),0);
                fwrite(&d3,sizeof(d3),1,fp);
                fclose(fp);
          break;

        }
        else{
            printf("\n\n No Such User Is Found");
            break;
        }


        }
    printf("\n\nEnter any key to go back to AdminMenu");
    getch();
    AdminMenu();
    printf("function is working");
}

int checkid3(int t){
    rewind(fp);
    while(fread(&d3,sizeof(d3),1,fp)!=0){
    if(d3.ID==t){
    return 0;
    }
    }

    return 1;
}


 void Exit(){
     system("cls");
     printf("Thank you for using this software\n\n");

 }


