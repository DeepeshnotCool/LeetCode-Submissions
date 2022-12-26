# Write your MySQL query statement below
 SELECT employee_id FROM Employees e WHERE employee_id NOT IN(SELECT employee_id FROM Salaries)
 UNION
 SELECT employee_id FROM Salaries s WHERE employee_id NOT IN(SELECT employee_id FROM Employees)
 ORDER BY employee_id;
# SELECT Employees.employee_id FROM Employees CROSS JOIN Salaries WHERE salary = null OR name = null;