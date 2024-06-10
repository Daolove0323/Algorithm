select book_id, date_format(published_date, '%Y-%m-%d') as published_date
from book
where year(published_date) = '2021'and category in ('인문')
order by published_date;