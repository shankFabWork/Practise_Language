show databases;

create database university_db;

use university_db;
show tables;

-- Student Type 1
drop table student;
create table student(
id int auto_increment primary key,
name varchar(10),
birth_date DATE,
ph_no varchar(12),	
gender varchar(1)
);

insert into 
student(id,name,birth_date,ph_no,gender)
values
(1,"shank","2000-05-25","91912325678","M"),
(2,"shank12","2000-04-12","91915625678","M");

select * from student;

-- ## List Of Constraints
-- NOT NULL
-- UNIQUE
-- DEFAUT
-- CHECK
-- FOREIGN KEY
-- PRIMARY KEY

-- Student Type 2
drop table student;
create table student(
id int auto_increment primary key,
name varchar(50) NOT NULL,
ph_no varchar(12) UNIQUE,
age int not null check(age>=18),
country varchar(20) default "INDIA"
);

insert into 
student(id,name,ph_no,age,country)
values
(1,"shank","91912325678",18,"Japan");

-- Age should be greater than or equal 18 
insert into 
student(id,name,ph_no,age,country)
values
(2,"gagan","919156725678",13,"Australia");

insert into 
student(name,ph_no,age,country)
values
("John","919154565678",25,"America");


insert into 
student(id,name,ph_no,age)
values
(3,"Pankaj","919156725678",21),
(4,"Rajneesh","91915724678",23),
(5,"Rohit","91915679624",23),
(6,"shivam","91915676378",23),
(7,"chanchal","91836576378",31),
(8,"Kamal","91917834378",35);

select * from student;
select * from student where age > 20;
select * from student where country != "Japan";
select * from student where country <> "Japan";
select * from student where country IN ("Japan","India");
select * from student where age IN (21,18);
select * from student where age between 20 and 22;
select * from student where name like "%an%";
select * from student where name like "%an_";

select * from student where name regexp "an";
select * from student where name regexp "^r";
select * from student where name regexp "l$";
select * from student where name regexp "an|al|^r";
select * from student where name regexp "a[mn]";
select * from student where name regexp "^[pr]";
select * from student where name regexp "[lh]$";

select * from student order by name asc;


select distinct(country) from student order by name asc;

select * from student;
select * from student limit 3;
select * from student limit 3,3;

select count(age) from student;
select min(age) from student;
select max(age) from student;
select sum(age) from student;
select avg(age) from student;
select avg(age) from student where country = "INDIA";

-- You are using safe update mode and you tried to update a table without a WHERE 
-- that uses a KEY column.  To disable safe mode, toggle the option in 
-- Edit -> Preferences -> SQL Editor and reconnect

-- Update Changes in The Tuple Value of Tables
update student
set country = "Africa"
where country = "Japan";

update student
set age = 29
where age = 23;

select * from student;

-- In order to work with commit and rollback
-- Edit -> Preferences -> SQL Execution -> New Connection use auto commit mode [uncheck]

select * from student;

-- commit 1
commit;

update student
set country="China"
where country="India";

select * from student;

rollback;

select * from student;

-- commit 2
select * from student;
commit;

delete from student
where country="INDIA";
select * from student;

rollback;
select * from student;
