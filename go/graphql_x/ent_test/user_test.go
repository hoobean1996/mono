package enttest_test

import (
	"context"
	"log"
	"testing"

	"entgo.io/ent/dialect"
	_ "github.com/mattn/go-sqlite3"
	"liquid.io/go/graphql_x/ent"
)

func TestUserSchema(t *testing.T) {
	client, err := ent.Open(dialect.SQLite, "file:ent?mode=memory&cache=shared&_fk=1")
	if err != nil {
		log.Fatalf("failed to connect to sqlite: %v", err)
	}
	defer client.Close()
	ctx := context.Background()
	if err := client.Schema.Create(ctx); err != nil {
		log.Fatalf("failed create schema resources: %v", err)
	}
	{
		user, err := client.User.Create().SetDisplayName("hebin").SetEmail("hebin@gmail.com").Save(ctx)
		if err != nil {
			log.Fatalf("failed to create a user with display name and email: %v", err)
		}
		if user.Email != "hebin@gmail.com" || user.DisplayName != "hebin" {
			t.FailNow()
		}
	}
}
