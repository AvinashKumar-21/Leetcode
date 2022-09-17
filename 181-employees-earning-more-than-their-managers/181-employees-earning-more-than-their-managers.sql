# Write your MySQL query statement below
select a.name as Employee from employee as a,employee as b where a.managerId=b.id and a.salary>b.salary; 