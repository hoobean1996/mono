import { useContext } from "react";
import {
  InternalRoute,
  InternalRouteMapContext,
} from "./InternalRouteMapContext";
import { InternalRouterLayout } from "./InternalRouterLayout";

type Props = {
  path: string;
};

function useInternalRoute(path: string): InternalRoute {
  const routeMap = useContext(InternalRouteMapContext);
  const route = routeMap[path];
  if (route == null) {
    return {
      path: "*",
      entrypoint: {
        root: <div>404</div>,
      },
    };
  }
  return route;
}

export function InternalRouter({ path }: Props) {
  const route = useInternalRoute(path);
  return <InternalRouterLayout>{route.entrypoint.root}</InternalRouterLayout>;
}
