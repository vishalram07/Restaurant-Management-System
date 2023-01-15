#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);  //Display Functions
void foodlist();
void view_order(int order, int quantity, int or_no);
void menu();  //Delete & Count Function
void deletefood(int serial);
int countitem();  //Extra design Function
void cls();
void printstring(char print[]);
void newline(int line);
void tabspace(int tab);
void spacebar(int space);
void pwellcome();
void align1(void);
void align2(void);  //START Structure Here
typedef struct Node node ;
struct Node
{
	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *link;
};
node *head, *list;
int main()
{
	system(">>>>>>>>>>> FOOD ORDERING MANAGEMENT SYSTEM <<<<<<<<<<<<");
	system("mode con: cols=80 lines=30");
	pwellcome();
	Sleep(300);
	cls();
	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;
	head = NULL;
	insertfirst(1,"Hot Cake ",8,475.00);         //creating linked list
	insertend(2,"Coffee   ",46,325.00);
	insertend(3,"Ice cream",46,230.00);
	insertend(4,"Sandwich ",34,320.00);
	insertend(5,"Burger   ",23,175.00);
	insertend(6,"Pizza   ",13,250.00);
	insertend(7,"Grill    ",7,100);
	insertend(8,"Pancakes ",121,350.00);
	insertend(9,"Cold Drinks",73,120.00);
	mainmenu:
	newline(1);
	menu();
	int menu_choice;
	newline(1);
	tabspace(4);
	fflush(stdin);
    scanf("%d",&menu_choice);
	switch(menu_choice)
     {
		case 1:               //order panel
		{
			foodlist:
			cls();
			printf("=> 0. Main Menu ");
			foodlist();
			break;
		}
		case 2:              //admin panel
		{
			int admin_panel_choice;
			adminpanelchoice:
			cls();
            align1();
            tabspace(4);
            printf("1. Main Menu\n\n\t");
            Sleep(300);
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");
			fflush(stdin);
            int p=0;
            char password[20];
            do
            {
                password[p]=getch();
                if(password[p]!='\r')       //password verification for admin panel
                {
                    printf("*");
                }
                p++;
            }while(password[p-1]!='\r');
            password[p-1]='\0';
			if(strcmp(password,"123321")==0)
            {
				node *temp;
				temp = list;
				admin_choice:
				cls();
                newline(5);
                tabspace(4);
                printstring("You are on Admin Pannel\n\n");
				tabspace(4);
				printf(" 1. Total Cash Today \n\n");Sleep(250);tabspace(4);     //functions in admin panel
				printf(" 2. View Card Pay \n\n");Sleep(250);tabspace(4);
				printf(" 3. Add Food \n\n");Sleep(250);tabspace(4);
				printf(" 4. Delete Food \n\n");Sleep(250);tabspace(4);
				printf(" 5. Instant Food List \n\n");Sleep(250);tabspace(4);
				printf(" 6. Item Counter \n\n");Sleep(250);tabspace(4);
				printf(" 7. Instant Order Preview\n\n");Sleep(250);tabspace(4);
				printf(" 0. Main Menu ");Sleep(250);
				int admin_choice;
				fflush(stdin);
                scanf("%d",&admin_choice);
				if(admin_choice==1)         //total profit
                {
					cls();
                    align1(); tabspace(4);
                    printf("Todays Total Cash : %0.2f  \n",totalmoney);
					Sleep(2000);
					goto admin_choice;
				}
				else if(admin_choice==2)    //card details
                {
					if(c!=0)
					{
						cls();  newline(3); tabspace(4);
						printf(" __________\n");tabspace(4);
						printf("|   Card NO.   |   Money $   |\n");tabspace(4);
						printf("------------------------------\n");tabspace(4);
						for(int z=1; z<=c;z++)
						{
							printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);tabspace(4);
							printf("------------------------------\n");tabspace(4);
							Sleep(150);
						}
						Sleep(1500);
					}
					if(c==0)
					{
                        cls();  align1(); tabspace(4);
                        printf("No Card History\n");}
                        Sleep(1500);
                        goto admin_choice;
				    }
				    else if(admin_choice==3)      //add new food item in the menu
				    {
                        foodadd:
                        cls();
                        char ffoodname[25];
                        int fquantity;
                        int fdata;
                        float fprice;
                        int fposi;
                        newline(3);tabspace(4);
                        printf(" Enter Food Name :  ");
					    fflush(stdin);
                        scanf("%[^\n]s",ffoodname);
					    fquantity:
                        fflush(stdin);
                        newline(2);tabspace(4);
                        printf(" Enter Food Quantity :  ");
                        scanf("%d",&fquantity); fflush(stdin);
                        foodserial:
					    newline(2);tabspace(4);
                        printf(" Enter Food Serial :  ");
                        scanf("%d",&fdata);
                        node *exist;
                        exist = list;
                      while(exist->data!=fdata)
                        {
                            if(exist->link==NULL)
                            {
                                break;
                            }
                        exist=exist->link;
                      }
                      if(exist->data==fdata)
                      {
                        cls(); newline(5);tabspace(3);
                        printf(" Food Serial Already Exist, Please Re-Enter  "); Sleep(2000);
                        goto foodserial;
                      }
                      fprice:
                      fflush(stdin);
					  newline(2);tabspace(4);
					  printf(" Enter Food Price :  ");
					  fflush(stdin);
                      scanf("%f",&fprice);
					  newline(2);tabspace(4);
					  printf("Submiting your data");
					  for(int i=0;i<4;i++)
                      {
                          printf(" .");
                          Sleep(500);
                      }
					 insertend(fdata,ffoodname,fquantity,fprice);
                     newline(2);tabspace(4);
                     printf("Adding Food  Successfull....\n");
					 Sleep(2000);
					 goto admin_choice;
				}
				else if(admin_choice==4)      //deleting a food from the menu
                    {
					cls();
					align1();tabspace(2);
					printf("Enter Serial No of the Food To Delete : ");
					int fdelete;
					fdelete:
					fflush(stdin);
                    scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete)
                    {
						temp = temp->link;
					}
					if(temp->data==fdelete)
					{
						deletefood(fdelete);
					}
					else
					{
						newline(2); tabspace(2);
                        printf("Please Enter Correct Number :  ");
                        Sleep(500);
						goto fdelete;
					}
					goto admin_choice;
				}
				else if(admin_choice==5)    //instant foodlist view
                    {
                        cls();
                        foodlist(); Sleep(1000);
                        newline(2);tabspace(4);
                        printf("1. <-- back  \n\n");tabspace(5);
					    fflush(stdin);
                        scanf("%d",&any);
                        goto admin_choice;
				    }
				else if(admin_choice==6)   //stock verification
                    {
                        citem = countitem();
                        cls();
                        for(int i=1;i<=citem;i++)
                        {
                            align1(); tabspace(4);
                            printf("Item Counting ");
                            printf(" %d ",i);
                            Sleep(150);
                            cls();
                        }
					cls();
					align1();tabspace(4);
					printf("Total Food Item is --> %d  \n",citem); Sleep(2000);
					goto admin_choice;
				}
				else if(admin_choice==7)    //instant order view
				{
					cls();
                    newline(2);
                    tabspace(2);
					printf("\n\t\t");
					printf("__________________ ");
					printf("\n\t\t");
					printf("|  Order No.  |    Name   |  Quantity |  In Stock |");
					printf("\n\t\t");
                    printf("------------------------------------------------------");
					for(int o=1;o<=order;o++)
                    {
						view_order(total_order[o],order_quantity[o],o);
					}
					newline(2);
					tabspace(4);
					printf("1. <-- back  \n\n");
					tabspace(5);
					fflush(stdin);
					scanf("%d",&any);
					goto admin_choice;
				}
				else if(admin_choice==0)   //menu view
                {
                  goto mainmenu;
				}
				else
				{
					newline(2);
                    tabspace(4);
                    printf("Please Select From List :  ");
                    Sleep(500);
					goto admin_choice;
				}
			}
			else if(admin_panel_choice==1)
            {
				goto mainmenu;
            }
			else
            {
				newline(2);
                tabspace(4);
                printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}
			break;
		}
		case 3:   //exit
        {
			cls();
			align1();
            tabspace(3);
            printf("Thank You For Using Our System \n\n\n\n\n\n\n");
			Sleep(1000);
			exit(1);
		}
        default:
		newline(2);
        tabspace(4);
        printf("Please Enter Correct Choice");
        Sleep(300);
		goto mainmenu;
		break;
	}
	int get_food_choice;
	newline(2);
    tabspace(3);
    fflush(stdin);
    printf("Place Your Order: ");   //place order
    scanf("%d",&get_food_choice);
    if(get_food_choice==0)
    {
		goto mainmenu;
	}
	node *temp;
	temp = list ;
	while(temp->data != get_food_choice)
	{
		temp = temp->link;
		if(temp==NULL)
		{
			newline(2);
            tabspace(4);
            printstring("Please Choice From List ");
            newline(2);
            Sleep(1000);
			goto foodlist;
		}
	}
	if(get_food_choice == temp->data)
    {
		fcquantity:
		newline(2);
        tabspace(4);
        printf("Enter Food Quantity : ");
		int fcquantity;
		fflush(stdin);
        scanf("%d",&fcquantity);
        cls();
		if(fcquantity==0)
        {
			cls();
            align1();
            tabspace(3);
            printf("Quantity Can not be Zero ");
            Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity)
        {
			cls();
            align1();
            tabspace(3);
            printf("Out of Stock ! ");
            Sleep(2000);
			goto foodlist;
		}
		align1();
		tabspace(4);
		printf("Choice food %s its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);
		tabspace(4);
		printf("1. Confirm to buy this \n\n");
		tabspace(4);
		printf("2. Food List  ");
        int confirm;
		confirm:
        fflush(stdin);
        scanf("%d",&confirm);
		if(confirm == 1 )
        {
			newline(2);
            tabspace(4);
            printf(" 1. Cash ");    //payment mode
			newline(2);
			tabspace(4);
            printf(" 2. Credit ");
			int payment;
			payment:
			fflush(stdin);
            scanf("%d",&payment);
			if(payment==1)
            {
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updatefood(get_food_choice,uquantity);
				cls();
                align1();
                tabspace(4);
                printf("===>THANK YOU<===");
				newline(2);
				tabspace(4);
				printf("Food Ordered Successfully ...");
				newline(2);
				tabspace(4);
				printf("1. Do you want to buy any other item? ");
				newline(2);
				tabspace(4);
				printf("2. Main Menu ");
				int ps_menu;
				psmenu:
				fflush(stdin);
				scanf("%d",&ps_menu);
				if(ps_menu==1)
                {
                    goto foodlist;
                }
				else if(ps_menu==2)
                {
                    goto mainmenu;
                }
				else
                {
                    newline(2);
                    tabspace(4);
                    printf("Please Choice from list : ");
                    goto psmenu;
                }
			}
			else if(payment==2)
            {
				int card_number[100];
				c++;
				cls();
                align1();
                tabspace(4);
                printf("Enter Your Card No : ");
				fflush(stdin);
				scanf("%d",&card_number[c]);
				cardno[c] = card_number[c];
				newline(2);
				tabspace(2);
				printf("Enter Your Card Pin   : ");
				fflush(stdin);
				int p=0;
				char pin[20];
                do
                {
					pin[p]=getch();
					if(pin[p]!='\r')    //pin verification
                    {
					    printf("*");
                    }
					p++;
				    }while(pin[p-1]!='\r');
                pin[p-1]='\0';
                getch();
				cardmoney[c] = temp->price*fcquantity;
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updatefood(get_food_choice,uquantity);
				newline(2);tabspace(4);
                printf("Payment Success...");
				newline(2);tabspace(4);
                printf("1. Do you want to place another order ? ");
				newline(2);tabspace(4);
				printf("2. Main Menu ");
			    int ps_menu2;
				psmenu2:
				scanf("%d",&ps_menu2);
				if(ps_menu2==1)
                {
                    goto foodlist;
                }
				else if(ps_menu2==2)
				{
                    goto mainmenu;
                }
				else
                {
                      newline(2);
                      tabspace(4);
                      printf("Please Choice from list : ");
                      goto psmenu2;
                }
			}
			else
            {
				newline(2);
                tabspace(4);
                printf("Enter Choice from List : ");
				goto payment;
			}
		}                             //END Confirm Y/y
		else if(confirm == 2)
        {
			goto foodlist;
		}
		else
		{
			newline(2);
			tabspace(4);
            printf("Enter Choise from List : ");
			goto confirm;
		}
	}                                   //end get food choice if line
	else
    {
		newline(2);
		tabspace(4);
        printstring("Please Choice From List ");
        newline(2);
        Sleep(300);
		goto foodlist;
	}                                  //end get food choice
    }


void cls()
{
	system("cls");
}
void printstring(char print[])
{
	printf("%s",print);
}
void newline(int line)
{
	for(int i=0; i<line;i++)
    {
		printf("\n");
	}
}
void tabspace(int tab)
{
	for(int i=0; i<tab;i++)
    {
		printf("\t");
	}
}
void spacebar(int space)
{
	for(int i=0; i<space;i++)
    {
		printf(" ");
	}
}
void menu()
{
	cls();
	newline(5);
    tabspace(3);
    printstring("===> 1. Order");
    Sleep(400);
	newline(2);
    tabspace(3);
    printstring("===> 2. Admin Panel");
    Sleep(400);
	newline(2);
	tabspace(3);
	printstring("===> 3. Exit");
	Sleep(400);
	newline(1);
}
void insertend(int data, char foodname[25], int quantity, float price)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->foodname,foodname);
	temp->link = NULL;
	if(head==NULL)
    {
		head = temp;
		list = head;
	}
	else
	{
		while(head->link != NULL)
		{
			head = head->link;
		}
		head->link = temp;
	}
}
void insertfirst(int data, char foodname[25], int quantity, float price)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data ;
	temp->price = price;
	strcpy(temp->foodname,foodname);
	temp-> quantity = quantity;
	temp->link = head;
	head = temp;
	list = head ;
}
void insertmid(int pos, int data, char foodname[25], int quantity, float price)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->foodname,foodname);
	while(head->link->data != pos )
    {
		head = head->link ;
	}
	temp->link = head->link;
	head->link = temp ;
}
void deletefood(int serial)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp = list;
	if(temp->data != serial)
    {
		while(temp->link->data != serial)
		{
			temp = temp->link;
		}
		if(temp->link->data == serial)
		{
			temp->link = temp->link->link;
			cls();
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
            for(int i=0;i<4;i++)
            {
                printf(" .");
                Sleep(400);
            }
			printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
            Sleep(500);
		}
		else
        {
			printf("\n\n\n\n\t\t\tFood Item Not Found\n");
            Sleep(500);
		}
		head = temp ;
	}
	else
    {
		temp = temp->link;
		cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
        for(int i=0;i<4;i++)
        {
            printf(" .");
            Sleep(400);
            printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
            Sleep(500);
	     	head = temp ;
		    list=head;
	    }
    }
}
void updatefood(int udata, int uquantity)
{
	node *temp;
	temp = list;
	while(temp->data!=udata)
    {
		temp = temp->link;
	}
	if(temp->data == udata)
	{
		temp->quantity = uquantity;
	}
}
int countitem()
{
	node *temp;
	temp = list;
	int countitem=0;
	if(temp==NULL)
    {
		countitem = 0;
	}
	else
	{
		countitem = 1;
		while(temp->link != NULL)
		{
			countitem++;
			temp = temp->link;
		}
	}
	return countitem;
}
void foodlist()
{
	printf("\n\t\t");
	printf("__________________ ");
	printf("\n\t\t");
	printf("|  Food No.  |   FooD Name   |  Price  |   In Stock   |");
	printf("\n\t\t");
	printf("-------------------------------------------------------");
	node *temp;
	temp = list;
	while(temp != NULL)
    {
		printf("\n\t\t");
		printf("|     %d      |    %s  |    %0.2f   |    %d    |",temp->data,temp->foodname, temp->price, temp->quantity);
		printf("\n\t\t");
		printf("-------------------------------------------------------");
		temp = temp->link ;
		Sleep(100);
	}
}
void view_order(int order, int quantity, int or_no)
{
	node *temp;
	temp = list;
	while(temp->data != order)
    {
		temp = temp->link;
	}
	if(temp->data == order)
	{
		printf("\n\t\t");
		printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);
		printf("\n\t\t");
		printf("-------------------------------------------------------");
		Sleep(100);
	}
}
void pwellcome()          //welcome screen
{
	char welcome[50]="WELCOME";
	char welcome2[50]=" TO";
	char welcome3[50]=" RESTAURANT";
	char welcome4[50]=" MANAGEMENT SYSTEM";
	char name[50] = "BY";
	char name3[50] = "GOKUL D(21PC12)";
	char name1[50] = "VISHAL RAM V A(21PC38)";
	char name2[50] = "YAMUNA SHREE P(21PC40)";
	printf("\n\n\n\n\n\t\t\t      ");
	for(int wlc=0; wlc<strlen(welcome);wlc++)
    {
		printf(" %c",welcome[wlc]);
		Sleep(200);
	}
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2);wlc2++)
	{
		printf(" %c",welcome2[wlc2]);
		Sleep(200);
	}
	printf("\n\n\t\t\t  ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++)
	{
        printf(" %c",welcome3[wlc3]);
		Sleep(200);
	}
	printf("\n\n\t\t   ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++)
	{
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E')
		{
            printf(" %c",welcome4[wlc3]);
		}
		else
		{
			printf(" %c",welcome4[wlc3]);
		}
		Sleep(200);
	}
	printf("\n\n\t\t\t\t   ");
	for(int wlc3=0; wlc3<strlen(name) ;wlc3++)
	{
			printf(" %c",name[wlc3]);
		Sleep(200);
	}
	printf("\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(name3) ;wlc3++)
	{
			printf(" %c",name3[wlc3]);
		Sleep(200);
	}
	printf("\n\n\t\t ");
	for(int wlc3=0; wlc3<strlen(name1) ;wlc3++)
	{
			printf(" %c",name1[wlc3]);
		Sleep(200);
	}
	printf("\n\n\t\t ");
	for(int wlc3=0; wlc3<strlen(name2) ;wlc3++)
	{
			printf(" %c",name2[wlc3]);
		Sleep(200);
	}
}
void align1(void)
{
	printf("\n\n\n\n\n\n\n");
}
void align2(void)
{
	printf("\t\t\t\t\t");
}
