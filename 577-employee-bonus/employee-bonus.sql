select e.name, sum(b.bonus) as bonus
from employee e
left join bonus b on e.empId=b.empId
group by e.name,e.empId
having sum(b.bonus)<1000 or bonus is null
