# Write your MySQL query statement below
select round(count(DISTINCT player_id)/(select count(distinct player_id ) 
FROM Activity),2) as fraction
FROM Activity
where (player_id,DATE_SUB(event_date,INTERVAL 1 DAY  )) IN(
select player_id,min(event_date) as first_login
from Activity
group by player_id
)