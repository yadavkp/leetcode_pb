# Write your MySQL query statement below
select a.product_id as product_id
from Products as a
-- left join Products as b
-- on  a.low_fats = b.recyclable
where a.low_fats = "Y" and a.recyclable = "Y";