test: 
	@gcc test.c rabbit.c -o test_unit 
	@./test_unit

clean:
	@rm test_unit

.PHNOY: test 


