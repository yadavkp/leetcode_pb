# Write your MySQL query statement below

-- select a.name,b.bonus
-- from Employee as a
-- left join Bonus as b
-- on a.empId = b.empId
-- where b.bonus is null or b.bonus < 1000;

with temp  as (

    select a.name ,b.bonus
    from Employee as a
    left join Bonus as b
    on a.empId = b.empId
    where ifnull(b.bonus,0) < 1000
    -- //where b.bonus is null or b.bonus < 1000
)
select * from temp;