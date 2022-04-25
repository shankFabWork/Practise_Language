
show databases;

use university_db;

drop table employee;
drop table country;
drop table state;
create table country
(
cid int primary key,
cname varchar(20)
);

insert into country 
values(1,"America"),
(2,"Australia"),
(3,"Asia"),
(4,"Africa"),
(5,"Antactica");

create table state
(
sid int primary key,
sname varchar(20)
);

insert into state
values(1,"Bejing"),
(2,"New Delhi"),
(3,"Mumbai"),
(4,"Pune"),
(5,"Bombay");


create table employee(
id int primary key auto_increment,
name varchar(20),
marks int check(marks>=0),
country_id int not null,
state_id int not null
);

insert into employee(name,marks,country_id,state_id)
values("shank",56,2,1),
("Rajan",77,1,2),
("Pankaj",98,3,4),
("ujjwal",16,5,5),
("Sankar",47,5,2),
("Kunal",78,2,1),
("Kamal",43,3,5),
("Rajan",24,2,1),
("Ranjan",75,4,1);

-- In order to see the working of left and right join do not add a foreign key
alter table employee
add foreign key(country_id) references country(cid);

-- This will not work if u will add foreign key
insert into employee(name,age,country_id)
values("chinu",56,9);


alter table employee
add foreign key(state_id) references state(sid);

select * from employee;
select * from country;

select * from employee e
INNER JOIN  country c
on e.country_id = c.cid; 

select * from employee e
LEFT JOIN  country c
on e.country_id = c.cid;

select * from employee e
RIGHT JOIN  country c
on e.country_id = c.cid;

select * from employee e
CROSS JOIN  country c
order by name asc;


select * from employee e
INNER JOIN state s
on e.state_id = s.sid
INNER JOIN country c
on e.country_id = c.cid;

-- Group By
select c.cname,count(c.cname)
from employee e
INNER JOIN state s
on e.state_id = s.sid
INNER JOIN country c
on e.country_id = c.cid
group by cname;

select s.sname,count(s.sname)
from employee e
INNER JOIN state s
on e.state_id = s.sid
INNER JOIN country c
on e.country_id = c.cid
group by sname
having count(s.sname)>1
order by sname asc;

-- All marks
select marks
from employee;

-- Second Largest marks
select name,max(marks) 
from employee
where marks <> (select max(marks)  from employee);

select * 
from employee
where id in (select id 
from employee
where name regexp "al");

-- All employee data will only be shown only and only if state_id=3 is exists or not
select * from employee
where exists ( select * from employee where state_id=3);

-- Union
drop table worker1;
drop table worker2;
create table worker1(name varchar(20),age int);
insert into worker1 values
("shank",24),
("rajan",24),
("pankaj",26);
create table worker2(name varchar(20),age int);
insert into worker2 values
("kamal",21),
("pranav",31),
("pankaj",20);

select * from worker1
union
select * from worker2;

select name from worker1
union
select name from worker2;

select name from worker1
union all
select name from worker2;

-- IF AND ELSE
select id,name,marks,
if(marks>50,"Pass","Fail") as Result
 from employee;

-- Case
select id,name,marks,
case
when marks<40 then "Fail"
when marks>=40 and marks<70 then "Average"
when marks>=71 and marks<90 then "Good"
when marks>=90 and marks<=100 then "Excellent"
else "Wrong Input type"
end as Result
from employee;

select * from employee;

update employee 
set marks =
(
case id 
when 7 then 90
when 8 then 40
when id then marks
end
 );

update employee 
set marks =
(
case id 
when 7 then 90
when 8 then 40
end
) 
where id in (7,8);
 
select * from employee;

-- ***** Add Column ***** 
-- ALTER TABLE table_name
-- ADD column_name datatype;

-- ***** Modify Column ***** 
-- ALTER TABLE table_name
-- MODIFY column_name datatype;

-- ***** Delete Column ***** 
-- ALTER TABLE table_name
-- DROP COLUMN column_name;

-- ***** Rename Column ***** 
-- ALTER TABLE table_name
-- CHANGE column_name New_name;	

-- ***** Rename Table ***** 
-- ALTER TABLE table_name 
-- RENAME new_table_name; 	


-- DROP AND TRUNCATE
create table demo(name varchar(20),marks int);
insert into demo values("rajan",30);
-- Drop Table 
drop table demo;
-- Truncate Table
select * from demo;
truncate table demo;

-- Create View
create or replace view everything as
select * from employee e
INNER JOIN state s
on e.state_id = s.sid
INNER JOIN country c
on e.country_id = c.cid;

select * from everything;

-- Alter View
alter view everything 
as
select * from employee;

select * from everything;

-- Drop view
drop view everything;

-- Indexing 
select * from student where age > 20;

create index student_age on student(age);

show index from student; 	


# 1st 2nd and 3rd salary
show databases;
create database employee_database;
use employee_database;
create table employee_data
(
sno int primary key auto_increment,
name varchar(20),
salary int 
);
insert into employee_data(name,salary)
values 
("shank","1000"),
("rajan","2000"),
("gagan","4000"),
("kaurav","4000"),
("pankaj","2000"),
("anchal","3000"),
("prakhar","5000"),
("pranav","6000"),
("gaurav","1000");

select DISTINCT(salary) 
from employee_data
order by salary desc;

-- third largest salary
select *
from employee_data
where salary=
(select DISTINCT(salary) 
from employee_data
order by salary desc
limit 2,1);

