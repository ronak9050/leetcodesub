SELECT e.name, SUM(b.bonus) AS bonus
FROM employee e
LEFT JOIN bonus b ON e.empId = b.empId
GROUP BY e.name, e.empId
HAVING SUM(b.bonus) < 1000 OR SUM(b.bonus) IS NULL;
