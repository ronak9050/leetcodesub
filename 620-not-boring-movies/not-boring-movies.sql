select *
from cinema as c
where MOD(c.id,2)=1 and c.description not in ('boring')
order by c.rating desc