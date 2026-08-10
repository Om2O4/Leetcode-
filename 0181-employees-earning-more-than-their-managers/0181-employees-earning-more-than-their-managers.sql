# Write your MySQL query statement below
select e.name as Employee from employee e, employee m where e.managerid=m.id and e.salary>m.salary;