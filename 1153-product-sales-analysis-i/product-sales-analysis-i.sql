SELECT PRODUCT.PRODUCT_NAME, SALES.YEAR, SALES.PRICE
FROM SALES
LEFT JOIN PRODUCT ON PRODUCT.PRODUCT_ID = SALES.PRODUCT_ID