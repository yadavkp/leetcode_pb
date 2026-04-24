# Write your MySQL query statement below

-- select max(salary) from Employee;
-- select distinct max(salary) as SecondHighestSalary
-- from Employee  
-- where salary  < (select max(salary) from Employee);

-- 
-- select  distinct salary as SecondHighestSalary
-- from Employee
-- order by salary desc
-- limit 1 offset 1;

select ifnull(
    (select  distinct salary as SecondHighestSalary
     from Employee
    order by salary desc
     limit 1 offset 1 ), 
     null)
 as SecondHighestSalary;
