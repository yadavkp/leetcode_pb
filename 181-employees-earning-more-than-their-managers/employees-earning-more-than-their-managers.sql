# Write your MySQL query statement below

select a.name AS Employee
from Employee as a
join Employee AS b
ON a.managerId = b.id
where a.salary > b.salary;
