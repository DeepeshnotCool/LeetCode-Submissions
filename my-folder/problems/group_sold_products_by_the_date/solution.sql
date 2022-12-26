# Write your MySQL query statement below

# SELECT sell_date FROM product WHERE sell_date IN 
# (SELECT COUNT(product) WHERE product IN 
#  (SELECT sell_date,product FROM Activities GROUP BY sell_date AS products) AS num_sold) ORDER BY sell_date;

# SELECT COUNT(product)  AS num_sold WHERE product IN
 # (SELECT sell_date,COUNT(product) AS num_sold, product AS products  FROM Activities GROUP BY sell_date);
# SELECT product, COUNT(product) AS num_sold FROM Activities GROUP BY sell_date;
# SELECT product, sell_date FROM Activities WHERE sell_date IN (SELECT DISTINCT(sell_date) FROM Activities) ; 
# SELECT DISTINCT(sell_date), product FROM Activities GROUP BY sell_date; 

SELECT sell_date, COUNT( DISTINCT product) AS num_sold , GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products FROM Activities GROUP BY sell_date ORDER BY sell_date;

# select sell_date, count( DISTINCT product ) as num_sold ,
    
#     GROUP_CONCAT( DISTINCT product order by product ASC separator ',' ) as products
    
#         FROM Activities GROUP BY sell_date order by sell_date ASC;