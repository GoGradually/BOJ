-- 코드를 입력하세요
SELECT dr_name, dr_id, mcdp_cd, DATE_FORMAT(hire_ymd,"%Y-%m-%d") AS HIRE_YMD FROM doctor
WHERE mcdp_cd = 'CS' OR mcdp_cd = 'GS'
ORDER BY HIRE_YMD DESC, DR_NAME ASC;