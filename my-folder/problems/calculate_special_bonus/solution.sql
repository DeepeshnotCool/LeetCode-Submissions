# Write your MySQL query statement below
SELECT employee_id,salary AS bonus FROM Employees WHERE employee_id%2 !=0 AND name  NOT LIKE 'M%'
 UNION 
SELECT employee_id, 0 AS bonus FROM Employees WHERE employee_id%2 =0 OR name   LIKE 'M%'ORDER BY employee_id;


# -- select entries with odd  employee id and name not start with M
#             select employee_id , salary as bonus 
#             from employees 
#             where employee_id%2 <>0 and name not like 'M%'
            
#         -- join both selection 
#             union
            
#         -- select remaining entries from table 
#             select employee_id , 0 as bonus
#             from employees
#             where employee_id%2 = 0 or name like 'M%'
#             order by employee_id;