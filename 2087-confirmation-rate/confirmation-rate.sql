SELECT s.user_id, 
       COALESCE(ROUND(COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END) * 1.0 / COUNT(s.user_id), 2), 0) AS confirmation_rate
FROM signups AS s
LEFT JOIN confirmations AS c ON s.user_id = c.user_id
GROUP BY s.user_id;
