# Write your MySQL query statement below
select a.product_id as product_id
from Products as a
left join Products as b
on  a.product_id = b.product_id
where a.low_fats = "Y" and a.recyclable = "Y";