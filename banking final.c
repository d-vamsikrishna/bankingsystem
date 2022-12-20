/***************MINI PROJECT ON BANKING SYSTEM IN C LANGUAGE*******************/
/*******developed by- VAMSI KRISHNA DESINNEDI(1602-21-748-059)*****************/
//Header Files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>//for using system("clear")function
//Structure to store user Data
struct user
{
	char phn_no[15];
	char ac_no[20];
	char pwd[20];
	float bal;
};
//Driver Code
void main()
{
	struct user user1,user2;
	int cnst=1;
	char fname[15],phn[15],pass[20],phn2[15];
	FILE *fp1,*fp2;
	int opt,ch,amt;
	printf("**********WELCOME TO DVK ONLINE BANKING SYSTEM**********\n");
	printf("--------------------------------------------------------");
	printf("\nIf NEW USER, To create a BANK ACCOUNT ------> enter 1");
	printf("\nIf already a USER, To LOG IN ------> enter 2");
	printf("\n\nENTER YOUR CHOICE..\n");
	scanf("%d",&opt);
	if(opt == 1)
	{
		system("clear");//Function to Clear the output Screen (or) Console
		printf("\nEnter the Account Number you want(only digits are advised):");
		scanf("%s",user1.ac_no);
		printf("Enter your Phone number(Excluding Country Code):");
		scanf("%s",user1.phn_no);
		printf("Enter your Password(Can be digits and characters):");
		scanf("%s",user1.pwd);
		user1.bal=0;//intially balance will be 0
		strcpy(fname,user1.phn_no);
		fp1=fopen(strcat(fname,".txt"),"w");//Phone Number as file Name
		fwrite(&user1,sizeof(user1),1,fp1);
		if(fwrite != 0)
		{
			printf("\n\nSuccesfully registered...!!");
		}
	}
	if(opt == 2)
	{
		system("clear");
		printf("\nEnter Registerd Phone Number:");
		scanf("%s",phn);
		printf("Enter Password:");
		scanf("%s",pass);
		fp1 = fopen(strcat(phn,".txt"),"r");
		if(fp1 == NULL) 
		{
		printf("NO DATA ATTACHED WITH THE ENTERED PHONE NUMBER..\nCHECK THE ENTERED PHONE NUMBER");
		}
		else 
		{
			fread(&user1,sizeof(struct user),1,fp1);
			fclose(fp1);
			if(!strcmp(pass,user1.pwd))
			//Checking whether the password set before and entered now are same or not
			{
				while(cnst == 1)
				{
				system("clear");
				printf("\n!!!!!*****WELCOME*****!!!!!");
				printf("\nHELLO, %s",user1.phn_no);
				printf("\nFor knowing CURRENT BALANCE ------> enter 1");
				printf("\nFor DEPOSIT ------> enter 2");
				printf("\nFor WITHDRAW ------> enter 3");
				printf("\nFor ONLINE TRANSACTIONS ------> enter 4");
				printf("\nFor PASSWORD CHANGE ------> enter 5");
				printf("\n-------------------------------------------");
				printf("\n\nEnter Any option from the Above mentioned list:\n");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1://For Checking Current Balance
						printf("CURRENT BALANCE is Rs. %.2f",user1.bal);
						break;
					case 2://For Deposit of  Money
						system("clear");
						printf("Enter the amount you want to DEPOSIT:");
						scanf("%d",&amt);
						user1.bal += amt;
						fp1= fopen(phn,"w");
						fwrite(&user1,sizeof(struct user),1,fp1);
						if(fwrite !=0)
						{
						    printf("\n\nDEPOSITION OF Rs.%d is SUCCESSFUL",amt);
						}
						fclose(fp1);
						break;
					case 3://For Withdraw of Money
						system("clear");
						printf("Enter the amount you want to WITHDRAWL:");
						scanf("%d",&amt);
						if(amt % 500 != 0) 
						{
						printf("\nPlease enter the Amount in Multiples of 500");
						}
						else if(amt>user1.bal) 
						{
						    printf("\nINSUFFICIENT BALANCE... CHECK AND TRY AGAIN!!!");
						}
						else 
						{
							user1.bal -= amt;
						    fp1 = fopen(phn,"w");
						    fwrite(&user1,sizeof(struct user),1,fp1);
						    if(fwrite !=0) 
						    {
						        printf("\n\nWITHDRAWL of  Rs.%d is SUCCESSFUL",amt);
						    }
						    fclose(fp1);
						}
						break;
					case 4://For transfer of Money
						printf("ENTER THE REGISTERED PHONE NUMBER OF THE PERSON TO WHOM YOU WANT TO TRANSFER:");
						scanf("%s",phn);
						printf("HOW MUCH AMOUNT DO YOU WANT TO TRANSFER:");
						scanf("%d",&amt);
						if(amt > user1.bal) 
						{
						    printf("\n*****INSUFFICIENT BALANCE*****");
						}
						else 
						{
							fp2 = fopen(strcat(phn,".txt"),"r");
							if(fp2==NULL) 
							{
							    printf("\n!!!ENTER A REGISTERED A NUMBER!!!");
							}
							else 
							{
								fread(&user2,sizeof(struct user),1,fp2);
								fclose(fp2);
								user2.bal += amt;
								fp2 = fopen(phn,"w");
								fwrite(&user2,sizeof(struct user),1,fp2);
								if(fwrite != 0)
								{
								    printf("\nPHONE NUMBER:%s",user2.phn_no);
									printf("\nYour trasfer is completed\nYou have trasnfered Rs.%d to %s",amt,user2.phn_no);
									fclose(fp2);
									user1.bal -= amt;
									strcpy(fname,user1.phn_no);
									fp1 = fopen(strcat(fname,".txt"),"w");
									fwrite(&user1,sizeof(struct user),1,fp1);
									fclose(fp1);
								}
							}
						}
						break;
					case 5://For Changing Password
						printf("\n\nEnter the CURRENT PASSWORD:");
						scanf("%s",pass);
						if(!strcmp(pass,user1.pwd))//Comparing passwords
						{
							printf("\n\nEnter the NEW PASSWORD:");
							scanf("%s",pass);
							strcpy(user1.pwd,pass);
							strcpy(fname,user1.phn_no);
							fp1 = fopen(strcat(fname,".txt"),"w");
							fwrite(&user1,sizeof(struct user),1,fp1);
							fclose(fp1);	
							printf("\nPASSWORD HAS BEEN SUCCESFULLY CHANGED..!!");
						}
						else 
						{
						    printf("\nSORRY!!! ENTER CORRECT PASSWORD");
						}
					default:
					break;
				}
				printf("\n----------------------------------------------------------------");
				printf("\nIf you want to do more Transactions\nENTER ------> 1\nelse ENTER ------> 0:");
				scanf("%d",&cnst);
				}
			}
			else 
			{
			    printf("---------------------------\n");
				printf("*****INVALID PASSWORD*****");
			}	
		}
	}
	if(opt!=1&&opt!=2)
	{
	    printf("!!.....Enter Only from the above mentioned List.....!!");
	}
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	printf("\n******THANKYOU FOR BANKING WITH US******");
}




