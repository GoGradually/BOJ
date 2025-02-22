-- 코드를 입력하세요
SELECT YEAR(os.sales_date) as YEAR, MONTH(os.sales_date) as MONTH, count(distinct(ui.user_id)) as PURCHASED_USERS, 
round(count(distinct(ui.user_id)) / (select count(*) from user_info as ui2 where YEAR(ui2.joined)=2021), 1) as PURCHASED_RATIO
from user_info as ui join (select os2.user_id, os2.sales_date from online_sale as os2 group by os2.user_id, YEAR(os2.sales_date), MONTH(os2.sales_date)) 
as os 
on ui.user_id = os.user_id
where YEAR(joined) = 2021
group by YEAR(os.sales_date), MONTH(os.sales_date)
order by YEAR asc, month asc;