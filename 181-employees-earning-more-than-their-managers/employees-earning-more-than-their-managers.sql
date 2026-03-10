# Write your MySQL query statement below

-- select a.name AS Employee
-- from Employee as a
-- join Employee AS b
-- ON a.managerId = b.id
-- where a.salary > b.salary;

select name as Employee
from Employee as a
where salary > (
    select salary 
    from Employee AS b
    where a.managerId = b.id
);
