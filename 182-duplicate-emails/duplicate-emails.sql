# Write your MySQL query statement below
select email 
from person 
 group by email     -- group rows 
having count(email) > 1;