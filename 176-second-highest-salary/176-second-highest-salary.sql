# Write your MySQL query statement below
select ifnull((select distinct salary from employee order by salary desc limit 1,1),NULL)as SecondHighestSalary;