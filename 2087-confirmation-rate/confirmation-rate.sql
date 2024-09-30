
select s.user_id, coalesce(round(count(case when action='confirmed' then 1 END )/count(c.user_id),2) ,0)as confirmation_rate
from signups as s
left join confirmations as c on s.user_id=c.user_id
group by s.user_id

