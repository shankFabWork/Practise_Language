show databases;

use employees;

show tables;



select * from employees;
select * from salaries;
select * from departments;
select * from dept_emp;

select e.*,s.*,d.*,de.*
from employees e,salaries s,departments d,dept_emp de
where e.emp_no = s.emp_no and d.dept_no = de.dept_no and de.emp_no = s.emp_no;

select e.*,s.salary
from employees e,salaries s
where e.emp_no = s.emp_no;

SHOW COLUMNS FROM employees;

-- emp_no
-- birth_date
-- first_name
-- last_name
-- gender
-- hire_date

-- All Data
select e.*,s.*,d.*,de.*
from employees e,salaries s,departments d,dept_emp de
where e.emp_no = s.emp_no and d.dept_no = de.dept_no and de.emp_no = s.emp_no;

-- Required Data
select e.*,s.salary,d.dept_name
from employees e,salaries s,departments d,dept_emp de
where e.emp_no = s.emp_no and d.dept_no = de.dept_no and de.emp_no = s.emp_no;


-- It will drop VIEW my_data if exists
DROP View IF EXISTS all_structured_data;

-- Creating VIEW of Required Data
CREATE VIEW all_structured_data AS
select e.*,s.salary,d.dept_name
from employees e,salaries s,departments d,dept_emp de
where e.emp_no = s.emp_no and d.dept_no = de.dept_no and de.emp_no = s.emp_no;

-- Get all Data
create view all_required_data AS
(select * from all_structured_data where dept_name="Sales" LIMIT 200)
union
(select * from all_structured_data where dept_name="Production" LIMIT 200)
union
(select * from all_structured_data where dept_name="Human Resources" LIMIT 200)
union
(select * from all_structured_data where dept_name="Research" LIMIT 200)
union
(select * from all_structured_data where dept_name="Quality Management" LIMIT 200)
union
(select * from all_structured_data where dept_name="Customer Service" LIMIT 200)
union
(select * from all_structured_data where dept_name="Marketing" LIMIT 200)
union
(select * from all_structured_data where dept_name="Finance" LIMIT 200);


-- -- --	Not Much Use
-- Count of number of rows
select count(*) from all_required_data;

-- All rows
select * from all_required_data limit 1600;

-- Get all the columns
SHOW COLUMNS FROM all_required_data;


-- -- --	Useful
-- Get Maximum Salary
select max(salary) as "Max Salary"
from all_required_data;

-- Get maximum salary in each Department 
select dept_name,max(salary) as "Max Salary"
from all_required_data
group by dept_name;



-- Get maximum salary in each Department using windows function
-- Use of window function
select *,max(salary) 
OVER(partition by dept_name) as "Max Salary"
from all_required_data;

select dept_name,row_number()
OVER(partition by dept_name) as "Max Salary"
from all_required_data;

-- Fetch First two employee from each department to join the company
select *,dept_name,max(salary)
OVER(partition by dept_name)
from all_required_data;

select emp_no,dept_name,max(hire_date)
OVER(partition by dept_name order by emp_no)
from all_required_data ;

select * from (
select hire_date,dept_name,row_number()
OVER(partition by dept_name order by emp_no) as rn
from all_required_data
) x
where x.rn < 3;

select * from (
select hire_date,dept_name,row_number()
OVER(partition by dept_name order by hire_date) as rn
from all_required_data
) x
where x.rn < 3;



