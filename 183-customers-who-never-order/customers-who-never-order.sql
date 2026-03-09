# Write your MySQL query statement below

-- select name
-- from Customers
-- foreign key   id references Orders(customerId)
-- where id != customerId ;

-- select a.name as Customers
-- from Customers as a
-- where id NOT IN (
--     select customerId from Orders
-- ) ;

select a.name as Customers
from Customers as a 
LEFT JOIN Orders b
on a.id  = b.customerId
where b.customerId is null;