# Write your MySQL query statement below

select e2.name as Employee from Employee e1, Employee e2 where e1.id = e2.managerId and e1.salary < e2.salary 
