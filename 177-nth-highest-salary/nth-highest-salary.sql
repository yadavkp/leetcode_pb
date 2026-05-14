CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.

      with temp as (
        select *, dense_rank() over 
        (order by salary desc) as rnk
        from Employee
      )
      select distinct salary from temp 
      where rnk = n
    --   where (select distinct)//
    --   // we have to find nth highest salary from the table 
        

  );
END