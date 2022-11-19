#include <iostream>
#include <cstring>
#define SIZE1 1;
#define SIZE2 2;
#define SIZE4 1;
#define SIZE5 1;
using namespace std;
// ------------------------PROTOTYPING CLASSES -----------------------------------
class User;
class Admin;
class Seller;
class Cart;
class Category;
class Customer;
class DeliveryDetails;
class Discount;
class Feedback;
class Order;
class OrderDetail;
class Payment;
class Product;
class Report;
// --------------------IMPLEMENTING CLASSES -------------------------------------
//class User
class User{
	protected:
		string name;
		string address;
		int phoneNo;
		string emailAddress;
	public:
		void verifyLogin();
		void displayDetails();
		void setUserDetails();
		User();
		User(string Name,string Address,int pnumber,string email);
		~User();
	};
//class Admin
class Admin:public User{
 	private:
 		string Admin_ID;
 		string password;
 		Customer *cus[SIZE5];
 		Seller *seller[SIZE5];
		 Report *report[SIZE5];
 	public:
		 void deleteItemDetails();
		 void updateItemDetails();
		 void createCategory();
		void manageusers();
 		Admin();
 		Admin(string Name,string Address,int pnumber,string email,stringadminid,string pass,Customer *cu,Seller *se,Report *re);
		~Admin();

	};

//Class Seller
	class Seller:public User{

	private:
		string Seller_ID;
		string password;
		Product *product[SIZE4];
		Discount *discount[SIZE4];
		Feedback *feedback[SIZE4];
	public:
		Seller(string Name,string Address,int pnumber,string email,string
		sellerid,string pass,int pid,int disid,int percentage,Feedback *f);
		Seller();
		~Seller();
		void addProductDetails();
		void approveFeedbacks();
	};

//Class Cart
	class Cart{
		private:
			int cart_ID;
			string cart_name;
		Product *product[SIZE2];
		
		public:
			Cart();
			Cart(int cartid,string cartname);
 			~Cart();
 			void addCartItem(Product *pro1,Product *pro2);
 			void deleteCartItem();
 			void calcTotalPrice;
 			void displayTotalPrice();
 			void Checkout();
		};
//Class Category
	class Category{
	
	private:
		int categoryID;
		string categoryName;
		string description;
		Product *product[SIZE1];
	public:
		void getProductsInCategory();
		void DisplayCategoryDetails();
		Category();
		Category(int categoryid,int pid);
	};

//Class Customer
	class Customer::public User{
		private:
			string Cust_ID;
			string password;
			Cart *cart;
		public:
			void addFeedback();
			void updateProfile();
			void search();
			void buyproduct();
	Customer();
		Customer(string Name,string Address,int pnumber,stringemail,string Custid,string pass,int cartid,string cartname);
		~Customer();
	};
//Class DeliveryDetails
	class DeliveryDetails{
		private:
		int deliveryID;
	public:
		DeliveryDetails();
		DeliveryDetails(int deliveryid);
		void updateDeliveryStatus();
		void displayDeliveryDetails();
		~DeliveryDetails();
	};
//Class Discount
	class Discount{
		private:
			int discount_ID;
			int Percentage;
			int discount;
		public:
			void generateDiscount();
			void addDiscount( Payment *p);
			void displayDiscount();
			Discount();
			Discount(int discountid,int percentage);
			~Discount();
	};
//Class Feedback
	class Feedback{
		private:
			int feedback_ID;
			string feedback_msg;
			string fname;
			int rate;
		public:
			void setFeedback();
			void displayFeedback();
			void displayRate();
			Feedback();
			Feedback(int fid,string name,int Rate);
			~Feedback();
	};
//Class Order
class Order{
		private:
			int orderID;
 			string orderStatus;
 			float orderTotal;
 			OrderDetail *orderdetails;
 			Payment *payment;
 			DeliveryDetails *deldetails;
		public:
			void placeOrder();
			void updateOrderStatus();
			void CalcOrderTotal();
			void setOrderDetails();
 			Order()
 			Order(int pid,float pamount,int orderid,int quantity,int deliveryid);
 			~Order();
	};
//Class OrderDetail
	class OrderDetail{
			private:
				int orderID;
 				int productID;
 				int quantity;
			public:
				void displayOrderTotal();
				void displayOrderDetails();
				OrderDetail();
				OrderDetail(int orderID,int quantity);
				~OrderDetail();
	};
//Class Payment
	class Payment{
			private:
				int paymentID;
				string payment_mode;
				string date;
				float amount;
			public:
				Payment();
				Payment(int pid,float pamount);
				void validatePayment();
				void addPayment();
				void displayPayment();
				void cancelPayment();
				~Payment();


		};
//Class Product
	class Product{
			private:
				int productID;
				string productName;
				string pro_description;
				float unit_price;
			public:
				Product();
				Product(int pid);
				~Product();
				void displayItemDetails();
				void displayAvailability();
				void deleteItemDetails();
				void setProductdetails();
};
//Class Report
	class Report{
		private:
			int reportNo;
		public:
			void generateitemReport();
			void generateCashflowReport();
			void displayReport();
 			Report();
 			Report(int repno);
 			~Report();
	};
// ----------------------IMPLEMENTING METHODS ---------------------------------
//User methods
User::User(){
	name="";
	address="";
	phoneNo=0;
	emailAddress="";
}
User::User(string Name,string Address,int pnumber,string email){
	name=Name;
	address=Address;
	phoneNo=pnumber;
	emailAddress=email;
}
	User::~User(){
	cout<<"Destructor is runing"<<endl;
}
	//Admin methods
	Admin::Admin(){
	Admin_ID="";
	password="";
}
	Admin::Admin(string Name,string Address,int pnumber,string email,stringadminid,string pass,Customer *cu,Seller *se,Report *re):User(stringName,string Address,int pnumber,string email){
		Admin_ID=adminid;
		password=pass;
		cus[0]=cu;
		seller[0]=se;
		report[0]=re;
}
	Admin::~Admin(){
		cout<<"admin deleted account"<<endl;
}
//Seller methods
	Seller::Seller(){
			Seller_ID="";
			password="";
			product[0]=new Product(0);
			discount[0]=new Discount(0,0);
		}
		Seller::Seller(string Name,string Address,int pnumber,string email,stringsellerid,string pass,int pid,int disid,int percentage,Feedback *f):User(stringName,string Address,int pnumber,string email){
			Seller_ID=sellerid;
			password=pass;
			product[0]=new Product(pid);
			discount[0]=new Discount(disid,percentage);
			feedback[0]=f;
	}
	Seller::~Seller()
		cout<<"Seller Deleted account"<<endl;
		delete product[0];
		delete discount[0];
		cout<<"End"<<endl;
	}
//Cart Methods
		Cart::Cart(){
		cart_ID=0;
		cart_name="";
}
		Cart::Cart(int cartid,string cartname){
		cart_ID=cartid;
		cart_name=cartname;

}
		void Cart::addCartItem(Product *pro1,Product *pro2){
		product[0]=pro1;
		product[1]=pro2;
}
	Cart::~Cart(){
	cout<<"cart is deleted"<<endl;
}
//Category methods
	Category::Category(){
	categoryID=0;
}
	Category::Category(int categoryid,int pid){
	categoryID=categoryid;
	product[0]=new Product(pid);
}
	Category::~Category(){
	 cout<<"category is removed"<<endl;
 	for(int i=0;i<SIZE1;i++){
 	delete product[i];
}
	cout<<"the end"<<endl;
}
//Customer methods
	Customer::Customer(){
		Cust_ID="";
		 password="";
		cart=new Cart(0,"");
}
Customer::Customer(string Name,string Address,int pnumber,stringemail,string Custid,string pass,int cartid,string cartname):User(stringName,string Address,int pnumber,string email){
	Cust_ID=Custid;
 	password=pass;
	cart=new Cart(cartid,cartname);
}
Customer::~Customer(){
		cout<<"Customer deleted account"<<endl;
		delete cart;
		cout<<"end"<<endl;
}
//DeliveryDetails methods
		DeliveryDetails::DeliveryDetails(){
		deliveryID=0;
}
		DeliveryDetails::DeliveryDetails(int deliveryid){
 		deliveryID=deliveryid;
}
		DeliveryDetails::~DeliveryDetails(){
		cout<<"Delivery Details ID:"<<deliveryID<<endl;
}
//Discount methods
Discount::Discount(){
		discount_ID=0;
		Percentage=0;
		 discount=0;
}
Discount::Discount(int discountid,int percentage){
		discount_ID=discountid;
		Percentage=percentage;
}
		void Discount::addDiscount( Payment *p){
		discount=(Percentage * p->displayPayment())/100;
}
	Discount::~Discount(){
		cout<<"discount removed"<<endl;
}
//Feedback methods
Feedback::Feedback(){
		feedback_ID=0;
		feedback_msg="";
		fname="";
 		rate=0;
}
Feedback::Feedback(int fid,string name,int Rate){
		feedback_ID=0;
		fname=name;
		rate=Rate;
}
		Feedback::~Feedback(){
		cout<<"Feedback was deleted"<<endl;
}
//Order methods
Order::Order(){ }
Order:: Order(int pid,float pamount,int orderid,int quantity,int deliveryid){
		orderdetails=new OrderDetail(orderid,quantity);
		payment=new Payment(pid,pamount);
		deldetails=new DeliveryDetails(deliveryid);
		orderID=orderid;
}
Order::~Order(){

 		cout<<"order ID:"<<orderID<<"deleted"<<endl;
 		delete orderdetails;
		 delete payment;
		delete orderdetails;
		 cout<<"the end"<<endl;
}
//OrderDetail methods
OrderDetail::OrderDetail(){
orderID=0;
quantity=0;
}
OrderDetail::OrderDetail(int orderid,int Quantity){
		orderID=orderid;
		quantity=Quantity;
}
		OrderDetail::~OrderDetail(){

 		cout<<"Order details deleted"<<endl;
}
//Payment method
Payment::Payment(){
		paymentID=0;
 		payment_mode=" ";
 		date=" ";
 		amount=0.0;
}
Payment::Payment(int pid,float pamount){
		paymentID=pid;
		amount=pamount;
}
		float displayPayment(){
		return amount;
}
		Payment::~Payment(){
		cout<<"deleted payment ID:"<<paymentID<<endl;
}
//product methods
Product::Product(){
		productID=0;
}
Product::Product(int pid){
		productID=pid;
}
Product::~Product(){
		cout<<"product is deleted"<<endl;
}
//Report methods
		Report::Report(){
		reportNo=0;
}
Report::Report(int repno){
		reportNo=repno;
}
Report::~Report(){
		cout<<"Report was deleted"<<endl;
}
//--------------------IMPLEMNTING MAIN METHOD---------------
int main()
{

	User* customer1=new Customer();// Creating object in Customer
	User* Seller1=new Seller();// Creating object in Seller
	User* admin1=new Admin();// Creating object in Admin
	Cart* cart1=new Cart();// Creating object in Cart
	Category* category1=new Category()// Creating object in Cartegory
	DeliveryDetails* deliverydetails1=new DeliveryDetails();
 // Creating object in DeliveryDetails
	Discount* discount1=new Discount();// Creating object in Discount
	Feedback* feedback1=new Feedback();// Creating object in Feedback
	Order* order1=new Order();//Creating object in Order
	OrderDetail* orderdetails=new OrderDetail();
 //Creating object in OrderDetail
	Payment* payment1=new Payment();//Creating object in Payment
	Product* Product1=new Product();//Creating object in Product
	Report* report1=new Report();//Creating object in Report
// calling functions
	cout << "\t-Customer-\n";
	customer1->verifyLogin();
	customer1->displayDetails();
	cout<<endl;
	cout << "\t-Seller-\n";
	Seller1->verifyLogin();
	Seller1->displayDetails();
	cout<<endl;
	cout << "\t-Admin-\n";
	admin1->verifyLogin();
	admin1->displayDetails();
	cout<<endl;
	cout << "\t-Cart-\n";
	cart1->addItem();
	cart1->CalcTotalPrice();
	cart1->DisplayTotalPrice();
	cart1->Checkout();
	cout<<endl;
	cout << "\t-Category-\n";
	category1->getProductsInCategory();
	category1->DisplayCategoryDetails();
	cout<<endl;
	cout << "\t-Category-\n";
	category1->getProductsInCategory();
	category1->DisplayCategoryDetails();
	cout<<endl;
	cout << "\t-DeliveryDetails-\n";
	DeliveryDetails->DeliveryDetails();
	DeliveryDetails->updateDeliveryStatus();
	cout<<endl;
	cout << "\t-Discount-\n";
	discount1->addDiscount();
	discount1->displayDiscout();
	cout<<endl;
	cout << "\t-Feedback-\n";
	feedback1->DisplayFeedback();
	feedback1->displayRate();
	cout<<endl;
	cout << "\t-Order-\n";
	order1->placeOrder();
	order1->Display();
	cout<<endl;
	cout << "\t-OrderDetail-\n";
	orderdetails->displayOrderTotal();
	orderdetails->displayOrderDetails();
	cout<<endl;
	cout << "\t-Payment-\n";
	payment1->addPayment();
	payment1->displayPayment();
	cout<<endl;
	cout << "\t-Product-\n";
	Product1->displayAvailability();
	Product1->displayItemDetails();
	cout<<endl;
	cout << "\t-Report-\n";
	report1->displayReport();
	report1->genarateItemReport();
	cout<<endl;

	delete customer1;
	delete Seller1;
	delete admin1;
	delete cart1;
	elete category1;
	delete deliverydetails1;
	delete discount1;
	delete feedback1;
	delete order1;
	delete orderdetails;
	delete payment1;
	delete Product1;
	delete report1;
	 return 0;
}