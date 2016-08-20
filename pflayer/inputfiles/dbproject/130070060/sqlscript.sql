create table customer(
	customer_id char(3) not null,
	name varchar(100) not null,
	date_of_birth date,
	address varchar(200) not null,
	occupation varchar(100) not null,
	primary key (customer_id)
	);
	
create table account(
	account_number char(4) not null,
	branch_id char(4) not null,
	customer1 char(3) not null,
	customer2 char(3),
	opening_date Date not null,
	overdraft_limit numeric(6,0) not null,
	current_balance numeric(6,0) not null,
	primary key (account_number),
	foreign key (customer1) references customer,
	foreign key (customer2) references customer,
	check ( current_balance >= -1*overdraft_limit),
	unique(customer1,branch_id),
	unique(customer2,branch_id)
	
	);
	
create table transaction(
	account_number char(4),
	trans_type varchar(6),
	mode varchar(6),
	date Date,
	time time,
	amount numeric(6,0),
	new_balance numeric(6,0),
	foreign key (account_number) references account,
	primary key(account_number,date,time)
	);
	
inSERT INTO customer  values('133','aka','1995-11-23','XYZ','ABC');
inSERT INTO customer  values('123','ama','1995-11-23','XYZ','ABC');
inSERT INTO customer values('143','ala','1995-11-23','XYZ','ABC');
inSERT INTO customer  values('135','ara','1995-11-23','XYZ','ABC');
inSERT INTO customer  values('136','dka','1995-11-23','XYZ','ABC');
inSERT INTO account  values('1234','0987','133',null,'2013-11-12',0,10000);
inSERT INTO account  values('1456','0987','123','143','2013-11-12',0,10000);
inSERT INTO account  values('1256','8976','133',null,'2013-11-12',4000,10000);
inSERT INTO account  values('1734','8976','143',null,'2013-11-12',0,10000);

insert into transaction values ('1234','credit','cash','2013-11-19','10:10:12',500,10500);
insert into transaction values ('1234','credit','cheque','2013-11-20','10:10:12',500,11000);
insert into transaction values ('1234','credit','cash','2013-11-23','10:10:12',500,11500);
insert into transaction values ('1234','debit','cheque','2013-11-24','10:10:12',500,11000);
insert into transaction values ('1456','credit','cash','2013-11-19','10:10:12',500,10500);
