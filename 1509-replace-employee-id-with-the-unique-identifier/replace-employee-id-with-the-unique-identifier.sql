# Write your MySQL query statement below

select a.name , b.unique_id
from Employees as a
Left join EmployeeUNI as b
on a.id = b.id;