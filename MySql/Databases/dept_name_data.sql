-- Data is very large so we need to get some data from dept_name

create view all_required_data AS
select * from all_structured_data where dept_name="Development" LIMIT 200
UNION
select * from all_structured_data where dept_name="Sales" LIMIT 200
UNION
select * from all_structured_data where dept_name="Production" LIMIT 200
UNION
select * from all_structured_data where dept_name="Human Resources" LIMIT 200
UNION
select * from all_structured_data where dept_name="Research" LIMIT 200
UNION
select * from all_structured_data where dept_name="Quality Management" LIMIT 200
UNION
select * from all_structured_data where dept_name="Customer Service" LIMIT 200
UNION
select * from all_structured_data where dept_name="Marketing" LIMIT 200
UNION
select * from all_structured_data where dept_name="Finance" LIMIT 200
