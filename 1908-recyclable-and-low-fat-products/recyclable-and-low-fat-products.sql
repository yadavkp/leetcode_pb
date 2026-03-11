# Write your MySQL query statement below

-- select a.product_id as product_id
-- from Products as a
-- where a.low_fats = "Y" and a.recyclable ="Y";

-- 2nd method subquery 

-- select a.product_id as product_id
-- from Products as a
-- where a.product_id in(
--     select product_id 
--     from Products
--     where low_fats ="y" and recyclable = "Y"
-- );


-- 3rd CTE WAY 

-- with temp AS (
--     -- your query what u want to write here
--     select product_id from Products
--     where low_fats = "Y"  and recyclable = "Y"
-- )
-- select product_id from temp;

-- 4th way to write by the Intersect way of two lists

select product_id 
from Products
 where low_fats = 'Y'
intersect
select product_id 
from Products
 where recyclable = 'Y';