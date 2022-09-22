#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;

struct mul_contact{ //to add multiple contact numbers for a user
    mul_contact *link;
    long long int cno;
};
struct Node{
	string name;                
	long long int phone_number; 
	Node *next;
	Node *prev;
    mul_contact *clink;
};

class ContactBook{
	Node *head;
	string ip_name;
	long long int ip_no;
	public:
		ContactBook()
		{
			head=NULL;
			ip_name="";
			ip_no=0;
		}
    	void CreateNode()
	    {
	    	if(head==NULL)
	    	{
    	    	Node *newptr= new Node;
	    	    cout<<"  Name of Contact: ";
		        cin>>ip_name;
		        newptr->name=ip_name;

    		    cout<<"  Phone Number: ";
	    	    cin>>ip_no;
		        newptr->phone_number=ip_no;
	
		        newptr->next=NULL;
		        newptr->prev==NULL;
		        head=newptr;
		        
	    		cout<<" _____________________________"<<endl;
		        cout<<"|         Contact Added       |"<<endl;
	    		cout<<"|_____________________________|"<<endl;
		    }
		    else
		    {
			
		        Node *newer= new Node;
	    	    cout<<"  Name of Contact: ";
		        cin>>ip_name;
		        newer->name=ip_name;
				Node *ctr=head;
				while(ctr){
					if(ctr->name==ip_name){
	    				cout<<" ___________________________________________________"<<endl;
						cout<<"| This Contact Name already exists. Try a new Name. |"<<endl;
	    				cout<<"|___________________________________________________|"<<endl;
						return;
					}
					ctr=ctr->next;
				}

    		    cout<<"  Phone Number: ";
	    	    cin>>ip_no;
		        newer->phone_number=ip_no;
		        
		        newer->next=NULL;
		        
		    	Node *temp=head;
		    	while(temp->next!=NULL)
		    	{
		    		temp=temp->next;
		    	}
		    	temp->next=newer;
		    	newer->prev=temp;
                newer->clink=NULL;
	    		cout<<" ______________________"<<endl;
		    	cout<<"|     Contact Added    |"<<endl;
	    		cout<<"|______________________|"<<endl;
			}
		}

        void add_to_existing(){
            Node* user_exist=searchbyName();
            if(user_exist){
                long long int no;
                mul_contact *mtr=new mul_contact;
                cout<<"  Enter Phone number:  "<<endl;
                cin>>no;
                mtr->cno=no;
                mtr->link=NULL;
                if(user_exist -> clink){
                    mul_contact *ctr=user_exist->clink;
                    while(ctr->link){
                        ctr=ctr->link;
                    }
                    ctr->link=mtr;
                }
                else{
                    user_exist->clink=mtr;
                }
	    		cout<<" ______________________________"<<endl;
                cout<<"| Contact Added successfully   |"<<endl;
	    		cout<<"|______________________________|"<<endl;
            }
            else{
	    		cout<<" _____________________________"<<endl;
	        	cout<<"|    Name Not Found.         |"<<endl;
                cout<<"|    Create new contact      |"<<endl;
	    		cout<<"|____________________________|"<<endl;
			}
        }

        Node* searchbyName(){
	    	Node *temp=head;
            cout<<"  Enter the Name: ";
	    	cin>>ip_name;
		    while(temp!=NULL){
		        if(temp->name==ip_name){
                    return temp;
		        }
		        temp=temp->next;
	        }
            return temp;
        }
		Node* searchbyNumber(){
			Node *temp=head;
            cout<<"  Enter the contact number: ";
	    	cin>>ip_no;
		    while(temp!=NULL){
		        if(temp->phone_number==ip_no){
                    return temp;
		        }
		        temp=temp->next;
	        }
            return temp;
		}

    	void Display()
    	{
	    	Node *temp=head;
	    	int count=0;
	    	
	    	if(temp==NULL)
	    	{
	    		cout<<" _____________________________________________"<<endl;
		    	cout<<"|  No Contacts... Please Add Some Contacts    |"<<endl;
	    		cout<<"|_____________________________________________|"<<endl;
	    	}
	    	else
	    	{
	    		BubbleSort();
				cout<<" ____________________________"<<endl;
	    		cout<<"|  Name:     "<<"  |    Number:  |"<<endl;
				cout<<"|______________|_____________|"<<endl;
	        	while(temp!=NULL)
	        	{
	        	    count++;
		        	cout<<"|  "<<temp->name<<" ";
		        	cout<<"|  "<<temp->phone_number;
                    mul_contact* ctr=temp->clink;
                    if(temp->clink){
                        cout<<"  "<<temp->clink->cno;
                        ctr=ctr->link;
                    }
                    while(ctr){
                        cout<<"  "<<ctr->cno; 
                        ctr=ctr->link;
                    }
                    cout<<endl;
    		    	temp=temp->next;		
	        	}
	    		cout<<" _____________________________"<<endl;
	        	cout<<"|  Total contacts: "<<count<<"          |"<<endl;
	    		cout<<"|_____________________________|"<<endl;
	    	}
    	}
    	Node* Search()
    	{
    		bool check=false;
	    	Node *temp=head;
	    	cout<<" _____________________________"<<endl;
	    	cout<<"|    1. Search By Name        |"<<endl;
	    	cout<<"|    2. Search By Number      |"<<endl;
	    	cout<<"|_____________________________|"<<endl;
	    	int option;
	    	cout<<"  Enter your option: ";
	    	cin>>option;
	  
	    	if(option==1){
				Node *user_exist=searchbyName();
		    	if(user_exist){
					cout<<"  Name: "<<user_exist->name<<endl;
		        	cout<<"  Phone Number: "<<user_exist->phone_number<<endl;
	    			cout<<"___________________________________"<<endl;
				}
	        	else
	        	{
	    			cout<<" _____________________________"<<endl;
	        		cout<<"|       Name Not Found        |"<<endl;
	    			cout<<"|_____________________________|"<<endl;
				}
				return user_exist;
	    	}
	    	else if(option==2)
	    	{
	    		Node *contact_exist=searchbyNumber();
				if(contact_exist){
					cout<<"  Name: "<<contact_exist->name<<endl;
		        	cout<<"  Phone Number: "<<contact_exist->phone_number<<endl;
	    			cout<<"___________________________________"<<endl;
				}
	        	else
	        	{
	    			cout<<" _____________________________"<<endl;
	        		cout<<"|   Contact no. Not Found     |"<<endl;
	    			cout<<"|_____________________________|"<<endl;
				}
				return contact_exist;
	    	}
	    }
	    void DeleteAllContacts()
	    {
	    	Node *temp=head;
	    	Node *temp2;
	    	if(head==NULL)
	    	{
	    		cout<<" _____________________________"<<endl;
				cout<<"|     Contact Book is Empty.  |"<<endl;
	    		cout<<"|_____________________________|"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}
				head=NULL;
				cout<<" _____________________________________"<<endl;
				cout<<"|  Successfully Deleted All Contacts  |"<<endl;
	    		cout<<"|_____________________________________|"<<endl;
			}
		}
		
		int DeleteContactBySearch()
    	{
	    	Node *temp=head;
	    	cout<<" ___________________________"<<endl;
	    	cout<<"|  1. Search By name        |"<<endl;
	    	cout<<"|  2. Search By Number      |"<<endl;
			cout<<"|___________________________|"<<endl;
	    	int option;
	    	cout<<"  Enter your option: ";
	    	cin>>option;
	  
	    	if(option==1)
	    	{
	    		bool Dcheck=false;
	    		Node* user_exist=searchbyName();
				if(user_exist)Dcheck=true;
	        	if(Dcheck==true)
	        	{
	            	int opt;
					cout<<" _________________________________"<<endl;
	            	cout<<"|  Press 1 to Delete the Contact  |"<<endl;
					cout<<"|_________________________________|"<<endl;
	            	cin>>opt;
	            	if(opt==1 & temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	            		temp=temp->next;
	            		delete temp1;
	        		
	            		temp->prev=NULL;
	            		head=temp;
						cout<<" ________________________________"<<endl;
			    		cout<<"|  Contact Deleted Successfully   |"<<endl;	
						cout<<"|_________________________________|"<<endl;
			    	}
			    	else if(opt==1 & temp->next==NULL)
			    	{
			    		temp->prev->next=NULL;
			    		delete temp;
			    		cout<<" ________________________________"<<endl;
			    		cout<<"|  Contact Deleted Successfully   |"<<endl;	
						cout<<"|_________________________________|"<<endl;
			    	}
			    	else if(opt==1)
			    	{
			    		Node *temp1;
			    		temp1=temp;
			    		temp->prev->next=temp1->next;
			    		temp->next->prev=temp1->prev;
			    		delete temp1;
						cout<<" ________________________________"<<endl;
			    		cout<<"|  Contact Deleted Successfully   |"<<endl;	
						cout<<"|_________________________________|"<<endl;
			    	}
			    	else
			    	{
			    		cout<<" ___________________________________"<<endl;
						cout<<"|  You have entered invalid option. |"<<endl;
						cout<<"|  Try Again with a valid option    |"<<endl;
						cout<<"|___________________________________|"<<endl;
		    		}
	            }
	            else if(Dcheck==false)
				{
					cout<<" ____________________________"<<endl;
					cout<<"|   Contact Name not found   |"<<endl;
					cout<<"|____________________________|"<<endl;
			    }  
	    	}
	    	else if(option==2)
	    	{
	    		bool Dcheck=false;
	    		Node* contact_exist=searchbyNumber();
				if(contact_exist)Dcheck=true;
	        	if(Dcheck==true)
	        	{
	            	int command;
					cout<<" _________________________________"<<endl;
	            	cout<<"|  Press 1 to Delete the Contact  |"<<endl;
					cout<<"|_________________________________|"<<endl;
	        	    cin>>command;
    	        	if(command==1 & temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	        	    	temp=temp->next;
	        		    delete temp1;
	        		
    	        		temp->prev=NULL;
	            		head=temp;
						cout<<" __________________________________"<<endl;
	            		cout<<"|   Contact Deleted Successfully   |"<<endl;
						cout<<"|__________________________________|"<<endl;
			    	}
				    else if(command==1 & temp->next==NULL)
    				{
	    				temp->prev->next=NULL;
		    			delete temp;
						cout<<" __________________________________"<<endl;
	            		cout<<"|   Contact Deleted Successfully   |"<<endl;
						cout<<"|__________________________________|"<<endl;
				    }
				    else if(command==1)
    				{
	    				Node *temp1;
		    			temp1=temp;
			    		temp->prev->next=temp1->next;
				    	temp->next->prev=temp1->prev;
					    delete temp1;
						cout<<" __________________________________"<<endl;
	            		cout<<"|   Contact Deleted Successfully   |"<<endl;
						cout<<"|__________________________________|"<<endl;
			    	}
				    else
				    {
						cout<<" _____________________________________________"<<endl;
	            		cout<<"| You have entered Wrong Command. Try Again   |"<<endl;
						cout<<"|_____________________________________________|"<<endl;
				    }
	            }
	            else if(Dcheck==false)
				{
					cout<<" _____________________________________________"<<endl;
	            	cout<<"|    Contact of this name doesn't exist.      |"<<endl;
					cout<<"|_____________________________________________|"<<endl;
				}
	    	}
	    	else
	    	{
				cout<<" _______________________"<<endl;
	    		cout<<"|    Invalid Option     |"<<endl;
				cout<<"|_______________________|"<<endl;
			}
	    }
	    void BubbleSort()
        {
        	Node *temp=head;
            Node *i,*j;
            string n;
            long long int n2;
            if(temp=NULL)
            {
				cout<<" _____________________________"<<endl;
	    		cout<<"|    ContactBook is empty     |"<<endl;
				cout<<"|_____________________________|"<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next)
                {
                    for(j=i->next;j!=NULL;j=j->next)
                    {
                        if(i->name>j->name)
		                {
                            n=i->name;
                            i->name=j->name;
                            j->name=n;
             
                            n2=i->phone_number;
                            i->phone_number=j->phone_number;
                            j->phone_number=n2;
                        }
                    }
                }
            }
        }
        
        
        int EditContacts()
    	{
	    	Node *temp=head;
	    	cout<<" ________________________"<<endl;
	    	cout<<"|  1. Search By Name     |"<<endl;
	    	cout<<"|  2. Search By Number   |"<<endl;
			cout<<"|________________________|"<<endl;
	    	int option;
	    	cout<<"  Enter your option: ";
	    	cin>>option;
	  
	    	if(option==1)
	    	{
	    		bool Echeck=false;
	    		Node* user_exist=searchbyName();
				if(user_exist)Echeck=true;				
	        	if(Echeck==true)
	        	{
	            	int command;
					cout<<" ________________________________"<<endl;
	        	    cout<<"|  Press 1 to Edit the Contact    |"<<endl;
					cout<<"|_________________________________|"<<endl;
	            	cin>>command;
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>ip_name;
	            		cout<<"  Enter New Number: ";
	            		cin>>ip_no;
	        		
	            		temp->name=ip_name;
	        	    	temp->phone_number=ip_no;

						cout<<" _________________________________"<<endl;
	        		    cout<<"|   Contact Edited Successfully   |"<<endl;
						cout<<"|_________________________________|"<<endl;
			    	}
			    	else
			    	{
					    cout<<" _________________________________"<<endl;
	        		    cout<<"|          Wrong Option           |"<<endl;
						cout<<"|_________________________________|"<<endl;
	    	        }
	    	    }
	    	    else if(Echeck==false)
	    	    {
					cout<<" _________________________________"<<endl;
	        		cout<<"|         Contact Not Found       |"<<endl;
					cout<<"|_________________________________|"<<endl;
				}
	        }
	    	else if(option==2)
	    	{
	    		bool Echeck=false;
	    		Node* contact_exist=searchbyNumber();
				if(contact_exist)Echeck=true;
	        	if(Echeck==true)
	        	{
	            	int command;
					cout<<" _______________________________"<<endl;
	        	    cout<<"|  Press 1 to Edit the Contact: |"<<endl;
					cout<<"|_______________________________|"<<endl;
	            	cin>>command;
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>ip_name;
	            		cout<<"  Enter New Number: ";
	            		cin>>ip_no;
	        		
	            		temp->name=ip_name;
	        	    	temp->phone_number=ip_no;

						cout<<" _________________________________"<<endl;
	        		    cout<<"|  Contact Edited Successully     |"<<endl;
						cout<<"|_________________________________|"<<endl;
			    	}
			    	else
			    	{
					    cout<<" _________________________________"<<endl;
	        		    cout<<"|          WRONG OPTION           |"<<endl;
						cout<<"|_________________________________|"<<endl;
	    	        }
	        	}
	        	else if(Echeck==false)
	        	{
	        	    cout<<"  There is No Contact of this Number."<<endl;
					cout<<" ________________________________________"<<endl;
	        		cout<<"|  This contact number doesn't exist     |"<<endl;
					cout<<"|________________________________________|"<<endl;
	            }
	        }
	        else
			{
			    cout<<" ________________________________________"<<endl;
	        	cout<<"|              WRONG OPTION              |"<<endl;
				cout<<"|________________________________________|"<<endl;
			}
	    }
	
    	
    	void OfflineSave()
    	{
    		Node *temp=head;
    		ofstream myfile ("contactbook.txt");
            if (myfile.is_open())
            {
            	while(temp!=NULL)
	        	{
	        	    myfile<<temp->name<<endl;
		        	myfile<<temp->phone_number<<endl;
    		    	temp=temp->next;		
	        	}
                myfile.close();
                CONTACTBOOK_Structure();
            }
            else
            {
				cout<<" ________________________________________"<<endl;
	        	cout<<"|             File is empty              |"<<endl;
				cout<<"|________________________________________|"<<endl;
			}
		}
		
		void reopenCB()
		{
			bool isEmpty;
			ifstream myfile ("contactbook.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
                while(getline(myfile,ip_name))
                {	
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          newer->name=ip_name;
		         
	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;
							
							newer->name=ip_name;
							newer->next=NULL;
							
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;		
						} 
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->phone_number==0)
                    	{
                    		
                    		 stringstream convert(ip_name);
			       	         convert>>ip_no;
                             temp->phone_number=ip_no;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	
		                	stringstream convert(ip_name);
			       	        convert>>ip_no;
		                	temp->phone_number=ip_no;
							
						}
                       
				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
				cout<<" _________________________________"<<endl;
            	cout<<"|            Empty file           |"<<endl;
				cout<<"|_________________________________|"<<endl;
				
			}
		}
		void CONTACTBOOK_Structure()
    	{
	    	cout<<" _____________________________"<<endl;
	    	cout<<"|  1. Add Contact             |"<<endl;
            cout<<"|  2. Add to existing contact |"<<endl;
	    	cout<<"|  3. Edit the Contact        |"<<endl;
	    	cout<<"|  4. Delete Contact          |"<<endl;
	    	cout<<"|  5. Search Contact          |"<<endl;
	    	cout<<"|  6. Display All Contacts    |"<<endl;
	    	cout<<"|  7. Delete All Contacts     |"<<endl;
	    	cout<<"|_____________________________|"<<endl;
		
	    	int Scommand;
	    	cout<<"  Enter your option: ";
	    	cin>>Scommand;
	    	try
	    	{
	    		if(Scommand>=1&&Scommand<=7)
	    		{
	    			if(Scommand==1)
	            	{
	            		CreateNode();
	            		OfflineSave();
	    	        	CONTACTBOOK_Structure();
	            	}
	            	else if(Scommand==2)
		        	{
		        		add_to_existing();
		        		OfflineSave();
		        		CONTACTBOOK_Structure();
			        }
	            	else if(Scommand==3)
	            	{
                        EditContacts();
                        OfflineSave();
	    	        	CONTACTBOOK_Structure();
	            	}
	            	else if(Scommand==4)
	            	{
                        DeleteContactBySearch();
                        OfflineSave();
	            		CONTACTBOOK_Structure();
	            	}
	            	else if(Scommand==5)
	            	{      	
	            		Search();
	            		CONTACTBOOK_Structure();
	            	}
	            	else if(Scommand==6)
	            	{	
	            		Display();
	            		CONTACTBOOK_Structure();	
		        	}
                    else if(Scommand==7)
		        	{
	            		DeleteAllContacts();
		        		OfflineSave();
		        		CONTACTBOOK_Structure();
			        }
				}
				else
				{
					throw(Scommand);
				}
			}
			catch(int Scommand)
			{
				cout<<" ____________________________________________________________"<<endl;
				cout<<"|  You have entered wrong option.Please select valid option. |"<<endl;
				cout<<"|____________________________________________________________|"<<endl;
				CONTACTBOOK_Structure();
			}	
	    }
    	
};

int main()
{   
    ContactBook cb;
    cb.reopenCB();
	string n;
	cout<<"  Please Enter Your Name: ";
	cin>>n;
    cout<<endl;
	cout<<"  WELCOME TO CONTACTBOOK, "<<n<<endl;
	cout<<"_________________________________"<<endl;
	cb.CONTACTBOOK_Structure();;
	return 0;
}