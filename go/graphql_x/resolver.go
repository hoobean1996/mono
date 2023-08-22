package graphql_x

import (
	"github.com/99designs/gqlgen/graphql"
	"liquid.io/go/graphql_x/ent"
)

// This file will not be regenerated automatically.
//
// It serves as dependency injection for your app, add any dependencies you require here.

type Resolver struct {
	client *ent.Client
}

func NewSchema(client *ent.Client) graphql.ExecutableSchema {
	return NewExecutableSchema(Config{Resolvers: &Resolver{client}})
}
