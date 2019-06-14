// This is a program system for tracking inventory levels, orders and sales and also creation of
// bills from sales.

    #include<iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <iomanip>
	#include <fstream>
	#include <ostream>

	using namespace std;

	//Global variable for total of items entered
	int productsub[100];
	int productsadd[100];
	ofstream file;
	ifstream ifile;
	string filename;
	int out;
	float itemtotal;
	string itemspurchased;
	string date;
	int productid;
	int itemsnum;
	int totalproducts;
	int defaultamount;
	int newamount;
	int price[9];
	int subproductsnum[100];
	int productsnum[100];
	int newproductsnum[100];
	string products[100] = {"Milk", "Rice", "Sugar", "Butter", "Bread", "Meat", "Fish", "Cereal", "Candy"};

	//function prototypes
	void displaystock(); // 4.
	void defaultstock();
	void items(); // 1.
	void search();
	void exportfile();
	void menu();
	void addproducts();	// 2.
	void deleteproducts(); //5.
	void disstock();
	void viewstock();
	void addmoreproducts();

	int main()
	{
		char yes;
		system("clear");
		cout << " MINIMAL Inventory Management System program for a Shop\n               Please Any Key  Proceed! ";
		cin >> yes;
		system("clear");
		menu();

		return 0;
	}

	//Function for program menu
	void menu()
	{
		int menunum;
		cout << "             Menu             \n";
		cout << "            ******";
		cout << "\n\n1.Add Products to Stock\n";
		cout << "2.Add Sales Made(This would Make changes in your number of units)\n";
		cout << "3.Generate bill(Can only Generate a Bill for one Item purchased)\n";
		cout << "4.Display Current Stock & save Data to file\n";
		cout << "5.Display Old Stock and Display Last Data saved\n";
		cout << "6.Search Item in Stock\n";
		cout << "7.Exit Program\n\n";

		cout << "Enter your choice here:";
		cin >> menunum;
		if (menunum == 1)
		{
			system("clear");
			addproducts();
			
		}
		else if (menunum == 2)
		{
			system("clear");
			items();
		}
		else if (menunum == 3)
		{
			system("clear");
			cout << "What is Today's Date?\n";
			cout << "Enter here: ";
			cin.ignore();
			getline(cin, date);
			exportfile();
		}
		else if (menunum == 4)
		{
			system("clear");
			displaystock();
		}
		else if (menunum == 5)
		{
			system("clear");
			disstock();
		}
		else if (menunum == 6)
		{
			system("clear");
			search();
		}
		else
		{
			system("clear");
			cout << "BYEEEEEE, HOPE TO SEE YOU AGAIN :)";
		}
	}

	//Function to Export data to file for printing
	void exportfile()
	{
		char exit;
		int itembought;
		string filename;
		ofstream file;
		cout << "What would you want the recent bill to be saved as? ";
		cin >> filename;
		system("clear");
		file.open(string(filename + ".txt").c_str());
		cout << "MilkID:0, RiceID:1, SugarID:2, ButterID:3, BreadID:4, MeatID:5, FishID:6, CerealID:7, CandyID:8\n";
		cout << "What was bought? Enter Product ID:";
		cin >> itembought;

		cout << "Writing to file...\n";
		cout << "About to finish...\n";
		file << "Product Bought: " << products[itembought] << "\n";
		file << "Amount to Pay: Gh¢" << price[itembought] << "\n";
		file << "Date :" << date << "\n";
		file << "\nThank You for doing business with us, Hope to see you soon!";
		cout << "\nDone! You can print out the bill now!";
		file.close();

		cout << "Press any key & <enter> to skip to menu";
		cin >> exit;

		if (exit != '/')
		{
			menu();
		}
	}

	//function for adding products to stock
	void addproducts()
	{

		int choice;

		cout << "1. Add products to stock" << endl;
		cout << "2. Go to menu  " << endl;
		cout << "3. View Stock" << endl;
		cout << "4. Add more products" << endl;

		cout << "Enter here: ";
		cin >> choice;

		if (choice == 1)
		{

			system("clear");
			for (int p = 0; p < 9; p++)
			{
				cout << "\nEnter Amount of " << products[p] << ": ";
				cin >> productsnum[p];
				cout << "Enter price of " << products[p] << ": Gh¢";
				cin >> price[p];
			}
		}
		else if (choice == 2)
		{
			menu();
		}
		else if (choice == 3)
		{
			viewstock();
		}
		else if (choice == 4)
		{
			addmoreproducts();
		}
		else
		{
			addproducts();
		}
		displaystock();
	}

	void addmoreproducts()
	{
		system("clear");

		cout << "\nWhich Product do you want to add? Enter It's ID here: ";
		cin >> productid;

		if (productid == 0)
		{
			cout << "Enter amount of Milk: ";
			cin >> productsadd[0];
			newproductsnum[0] = productsnum[0] + productsadd[0];

			addproducts();
		}
		else if (productid == 1)
		{

			cout << "Enter amount of Rice: ";
			cin >> productsadd[1];
			newproductsnum[1] = productsnum[1] + productsadd[1];

			addproducts();
		}
		else if (productid == 2)
		{
			cout << "Enter amount of Sugar : ";
			cin >> productsadd[2];
			newproductsnum[2] = productsnum[2] + productsadd[2];

			addproducts();
		}
		else if (productid == 3)
		{
			cout << "Enter amount of  Butter: ";
			cin >> productsadd[3];

			newproductsnum[3] = productsnum[3] + productsadd[3];
			addproducts();
		}

		else if (productid == 4)
		{
			cout << "Enter amount of  Bread: ";
			cin >> productsadd[4];
			newproductsnum[4] = productsnum[4] + productsadd[4];

			addproducts();
		}
		else if (productid == 5)
		{
			cout << "Enter amount of  Meat: ";
			cin >> productsadd[5];
			newproductsnum[5] = productsnum[5] + productsadd[5];

			addproducts();
		}
		else if (productid == 6)
		{
			cout << "Enter amount of  Fish: ";
			cin >> productsadd[6];
			newproductsnum[6] = productsnum[6] + productsadd[6];

			addproducts();
		}
		else if (productid == 7)
		{
			cout << "Enter amout of Cereal: ";
			cin >> productsadd[7];
			newproductsnum[7] = productsnum[7] + productsadd[7];

			addproducts();
		}
		else if (productid == 8)
		{
			cout << "Enter amount of  Candy: ";
			cin >> productsadd[8];
			newproductsnum[8] = productsnum[8] + productsadd[8];

			addproducts();
		}
		else
		{
			cout << "No product with that ID, try again!\n\n";
			addproducts();
		}
	}

	//Function for items the user enters
	void items()
	{
		int itemsnum;
		char exit;
		cout << "Get ready to enter item(s) Purchased\n";
		cout << "Press 'e' & <enter> to skip to menu or any other key & <enter> to proceed\n\n";
		cin >> exit;

		if (exit == 'e')
		{
			menu();
		}
		else
		{
			cout << "MilkID:0, RiceID:1, SugarID:2, ButterID:3, BreadID:4, MeatID:5, FishID:6, CerealID:7, CandyID:8\n";
			cout << "Enter ID of item Purchased: ";
		}

		cin >> productid;

		if (productid == 0)
		{

			cout << "Enter amount of Milk: ";
			cin >> productsub[0];
			subproductsnum[0] = productsnum[0] - productsub[0];
			items();
		}
		else if (productid == 1)
		{
			cout << "Enter amount of Rice: ";
			cin >> productsadd[1];
			subproductsnum[1] = productsnum[1] - productsub[1];
			items();
		}
		else if (productid == 2)
		{
			cout << "Enter amount of Sugar : ";
			cin >> productsub[2];
			subproductsnum[2] = productsnum[2] - productsub[2];
			items();
		}
		else if (productid == 3)
		{
			cout << "Enter amount of  Butter: ";
			cin >> productsub[3];
			subproductsnum[3] = productsnum[3] - productsub[3];
			items();
		}

		else if (productid == 4)
		{
			cout << "Enter amount of  Bread: ";
			cin >> productsadd[4];
			subproductsnum[4] = productsnum[4] - productsub[4];
			items();
		}
		else if (productid == 5)
		{
			cout << "Enter amount of  Meat: ";
			cin >> productsub[5];
			subproductsnum[5] = productsnum[5] - productsub[5];
			items();
		}
		else if (productid == 6)
		{
			cout << "Enter amount of  Fish: ";
			cin >> productsub[6];
			subproductsnum[6] = productsnum[6] - productsub[6];
			items();
		}
		else if (productid == 7)
		{
			cout << "Enter amout of Cereal: ";
			cin >> productsub[7];
			subproductsnum[7] = productsnum[7] - productsub[7];
			items();
		}
		else if (productid == 8)
		{
			cout << "Enter amount of  Candy: ";
			cin >> productsub[8];
			subproductsnum[8] = productsnum[8] - productsub[8];
			items();
		}
		else
		{
			cout << "No product with that ID, try again!\n\n";
			items();
		}
	}

	void calculatestock()
	{
		for (productid = 0; productid < 9; productid++)
		{
			productsnum[productid] = productsnum[productid] + newproductsnum[productid];
			subproductsnum[productid] = newproductsnum[productid] - productsub[productid];
		}
	}
	void displaystock()
	{
		cout << "ProductID\t\t"
		<< "Products"
		<< "\t"
		<< "Num of Products"
		<< "\t\t"
		<< "New Num of Products"
		<< "\tUnit Price" << endl;
		for (productid = 0; productid < 9; productid++)
		{
			subproductsnum[productid] = productsnum[productid] - productsub[productid];
			productsnum[productid] = productsnum[productid] + newproductsnum[productid];
			cout << productid << "\t\t\t" << products[productid] << "\t\t\t" << productsnum[productid] << "\t\t" << subproductsnum[productid] << "\t\t\t Gh¢" << price[productid] << endl;
		}
		file.open("DefaultSTOCK");

		file << "ProductID\t\t"
		<< "Products"
		<< "\t"
		<< "Num of Products"
		<< "\t\t"
		<< "New Num of Products"
		<< "\t\tUnit Price" << endl;
		for (productid = 0; productid < 9; productid++)
		{
			file << productid << "\t\t\t" << products[productid] << "\t\t\t" << productsnum[productid] << "\t\t\t" << subproductsnum[productid] << "\t\t\t Gh¢" << price[productid] << endl;
		}
		cout << "\nWriting to file...\n";
		cout << "Done writing new stock to file....\n";
		cout << "You file is automatically saved as ''DefualtSTOCK'' ";

		int out;
		cout << "press any number to proceed";
		cin >> out;
		if (out != 0)
		{
			menu();
		}
	}

	void disstock()
	{
		ifile.open("DefaultSTOCK");
		if (ifile.is_open())
		{
			string getcontent;
			while (getline(ifile, getcontent))
			{
				cout << getcontent << endl;
			}
		}
		int out;
		cout << "\n\npress any number to proceed";
		cin >> out;
		if (out != 0)
		{
			menu();
		}
	}
	void viewstock()
	{
		ifile.open("DefaultSTOCK");
		if (ifile.is_open())
		{
			string getcontent;
			while (getline(ifile, getcontent))
			{
				cout << getcontent << endl;
			}
		}
		int product_menu;
		cout << "\nPress any number to go to continue  ";
		cin >> product_menu;
		if (product_menu != 0)
		{
			system("clear");
			addproducts();
		}
		file.close();
	}
	void search()
	{
		int productid;
		char exit;
		cout << "Press 'e' & <enter> to exit or & other key to proceed & <enter>" << endl;
		cin >> exit;
		if (exit != 'e')
			{
			cout << "MilkID:0, RiceID:1, SugarID:2, ButterID:3, BreadID:4, MeatID:5, FishID:6, CerealID:7, CandyID:8\n";
			cout << "What product's information do you want to see? Enter it's ID here: ";
			cin >> productid;
			if (productid == 0)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[0] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[0] << "\n";
				cout << "UNIT PRRICE:" << price[0] << endl;

				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}
			else if (productid == 1)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[1] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[1] << "\n";
				cout << "UNIT PRRICE:" << price[1] << endl;

				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}
			else if (productid == 2)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[2] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[2] << "\n";
				cout << "UNIT PRRICE:" << price[2] << endl;
			}
			else if (productid == 3)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[3] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[3] << "\n";
				cout << "UNIT PRRICE:" << price[3] << endl;

				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}

			else if (productid == 4)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[4] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[4] << "\n";
				cout << "UNIT PRRICE:" << price[4] << endl;
				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}
			else if (productid == 5)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[5] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[5] << "\n";
				cout << "UNIT PRRICE:" << price[5] << endl;
				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}
			else if (productid == 6)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[6] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[6] << "\n";
				cout << "UNIT PRRICE:" << price[6] << endl;
				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}
			else if (productid == 7)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[7] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[7] << "\n";
				cout << "UNIT PRRICE:" << price[7] << endl;
				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}
			else if (productid == 8)
			{
				cout << "\t\tPRODUCT DETAILS\n";
				cout << "PRODUCT NAME:" << products[8] << "\n";
				cout << "TOTAL UNITS IN STOCK:" << subproductsnum[8] << "\n";
				cout << "UNIT PRRICE:" << price[8] << endl;
				cout << "Press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
				cin >> exit;

				if (exit == 'e')
				{
					menu();
				}
				else if (exit == 's')
				{
					system("clear");
					search();
				}
			}
			else
			{
				system("clear");
				search();
			}
		}
		else
		{
			menu();
		}
	}
