SELECT e1.name
FROM employee e1
INNER JOIN employee e2 ON e1.id = e2.managerId
GROUP BY e2.managerId
HAVING COUNT(e2.id) >= 5