import great_expectations as gx

context = gx.get_context()

validator = context.sources.pandas_default.read_csv(
    "https://raw.githubusercontent.com/great-expectations/gx_tutorials/main/data/yellow_tripdata_sample_2019-01.csv"
)

validator.expect_column_values_to_not_be_null("pickup_datetime")
validator.expect_column_values_to_be_between(
    "passenger_count", min_value=1, max_value=6
)
validator.save_expectation_suite(discard_failed_expectations=False)

checkpoint = context.add_or_update_checkpoint(
    name="my_quickstart_checkpoint",
    validator=validator,
)

checkpoint_result = checkpoint.run()

context.view_validation_result(checkpoint_result)
