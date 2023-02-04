# Write your MySQL query statement below

select d.name as Department, e.name as Employee, e.salary as Salary from employee e inner join department d on e.departmentId = d.id 
where (e.departmentId, e.salary) in (select e.departmentId, max(e.salary) from employee e group by e.departmentId)  
