select
case when month(differentiation_date) <= 3 then '1Q'
when month(differentiation_date) <= 6 then '2Q'
when month(differentiation_date) <= 9 then '3Q'
else '4Q' END quarter, count(*) ecoli_count
from ecoli_data
group by case when month(differentiation_date) <= 3 then '1Q'
when month(differentiation_date) <= 6 then '2Q'
when month(differentiation_date) <= 9 then '3Q'
else '4Q' end
order by quarter;