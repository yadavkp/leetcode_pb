# Write your MySQL query statement below

-- select a.product_id as product_id
-- from Products as a
-- where a.low_fats = "Y" and a.recyclable ="Y";

select a.product_id as product_id
from Products as a
where a.product_id in(
    select product_id 
    from Products
    where low_fats ="y" and recyclable = "Y"
);