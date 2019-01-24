.PHONY: clean All

All:
	@echo "----------Building project:[ sequenceAlignment - Debug ]----------"
	@cd "sequenceAlignment" && "$(MAKE)" -f  "sequenceAlignment.mk"
clean:
	@echo "----------Cleaning project:[ sequenceAlignment - Debug ]----------"
	@cd "sequenceAlignment" && "$(MAKE)" -f  "sequenceAlignment.mk" clean
