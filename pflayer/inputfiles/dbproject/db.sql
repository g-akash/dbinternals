create table junta(
username varchar(20),
name varchar(100) not null,
password varchar(20) not null,
DOB Date not null,
num_followers integer not null,
num_following integer not null,
email_id varchar(100) not null,
primary key(username),
check(num_followers>=0),
check(num_following>=0),
check(email_id like '%@%.com')	
)


create table followers(
	follower varchar(20) references junta(username) not null,
	followed varchar(20) references junta(username) not null,
	primary key(follower, followed)
)

create table tweets(
tweet_id char(10),
tweeter varchar(20) references junta(username) not null,
body varchar(140) not null,
tweet_time time not null,
num_likes integer not null,
num_retweets integer not null,
primary key(tweet_id),
check(num_likes>=0),
check(num_retweets>=0)
)

create table comments(
tweet_id char(10) not null,
comment_id integer not null,
commenter varchar(20) not null ,
body varchar(140) not null,
commenting_time time not null,
primary key(tweet_id,comment_id),
foreign key(commenter) references junta(username),
check(comment_id>0)
)

create table messages(
sender varchar(20) not null,
receiver varchar(20) not null,
body varchar(160) not null,
sent_time time not null,
primary key(sender,receiver,sent_time)
foreign key(sender) references junta(username),
foreign key(receiver) references junta(username)
)

create table likes(
liker varchar(20) not null,
tweet_id char(10) not null,
primary key(liker,tweet_id)
foreign key(liker) references junta(username),
foreign key(tweet_id) references tweets(tweet_id)
)

create table retweets(
tweet_id char(10) not null,
retweeter varchar(20) not null,
primary key(tweet_id,retweeter),
foreign key(tweet_id) references tweets(tweet_id),
foreign key(retweeter) references junta(username)
)
