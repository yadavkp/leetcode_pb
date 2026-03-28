# Write your MySQL query statement below



-- select  distinct a.contest_id
--         , round(count(b.user_id) *100.0 / (select count(*) from Users) , 2) as percentage
-- from Register as a
-- left join Users as b
-- on a.user_id = b.user_id
-- group by a.contest_id
-- order by  percentage desc, a.contest_id asc; 

select contest_id,
        Round(
            count(user_id) * 100.0 /  (select count(*) from Users),2

        ) as percentage 
from Register 
group by contest_id
order by percentage desc, contest_id asc;
