select history_id, car_id,
date_format(start_date, '%Y-%m-%d') START_DATE,
date_format(end_date, '%Y-%m-%d') END_DATE, 
case when (datediff(end_date, start_date) >= 29) THEN '장기 대여'
else '단기 대여' end RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where year(start_date) = 2022 and month(start_date) = 9
order by history_id desc;

